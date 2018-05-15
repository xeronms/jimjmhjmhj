#include <iostream>
#include <string>

#define INDEX r*i+j

typedef unsigned int uint;

using namespace std;

class error{
protected:
	error(){	printf("ERR\n");}
};
	class size_err : public error{};
	class zero_err : public error{};



class Matrix{
	double *data;
	unsigned int r, c;

public:
	Matrix(unsigned int r_,unsigned int c_):r(r_),c(c_){
		data = new double [r_*c_];
}
	Matrix(const Matrix &m):r(m.r),c(m.c){
		data = new double [r*c];
		memcpy(data, m.data, r*c*sizeof(double));
}
	~Matrix(){
		delete [] data;
}
	Matrix &operator=(const Matrix &m){
		r = m.r; c = m.c;
		delete [] data;
		data = new double [r*c];
		memcpy(data, m.data, r*c*sizeof(double));
		return *this;
}

	void init(double);
	void rysuj() const;
	double operator()(uint a, uint b) const;
	Matrix operator()(uint a, uint b, double val);
	Matrix operator+(const Matrix&) const;
	Matrix operator-(const Matrix&) const;
	Matrix operator-() const;
	Matrix operator*(double) const;
	Matrix operator*(const Matrix&) const;
	Matrix transpozycja();
	double wyznacznik() const;
	bool operator==(const Matrix&) const;
	bool operator!=(const Matrix&) const;
};
Matrix operator*(double, const Matrix&);




void Matrix::init(double a){
		for (uint i=0; i<r*c; ++i){
			data[i]=a;
		}
}

void Matrix::rysuj() const{
	for (uint i=0; i<(r*c); ++i){
		std::cout << data[i] << "\t";
		if (!((i+1)%c)) std::cout << std::endl;
	}
	std::cout << std::endl;
}

double Matrix::operator()(uint i, uint j) const{ //returning element [i,j]
	return data[INDEX];
}

Matrix Matrix::operator()(uint i, uint j, double val){ //swaping [i,j] element data with val
	 data[INDEX] = val;
	 return *this;
}

Matrix Matrix::operator+(const Matrix& m) const{
	if (r!=m.r || c!=m.c) throw size_err();
	Matrix m2(r,c);

	for (uint i=0; i<r*c; ++i){
		m2.data[i] = m.data[i] + data[i];
	}
	return m2;
}

Matrix Matrix::operator-() const{
	return (*this)*(-1);
}

Matrix Matrix::operator-(const Matrix& m) const{
	return *this + (-m);

}

Matrix Matrix::operator*(double k) const{
	Matrix m(r,c);
	for (uint i=0; i<r*c; ++i){
		m.data[i] = data[i] * k; 
	}
	return m;
}


Matrix Matrix::operator*(const Matrix& m) const{
	if (c!=m.r) throw size_err();
	Matrix m2(r,m.c);
	for (uint i=0; i<r; ++i){
		for (uint j=0; j<m.c; ++j){
			m2.data[i*m.c+j] = 0;
			for (uint k=0; k<c; ++k){
				m2.data[i*m.c+j] += data[i*c+k]*m.data[m.c*k+j];
			}
		}
	}
	return m2;
}

Matrix operator*(double k, const Matrix& m){
	return m*k;
}


Matrix Matrix::transpozycja(){
	Matrix m(*this);
	for (uint i=0; i<r; ++i){
		for (uint j=0; j<c; ++j){
			data[INDEX] = m.data[j*r+i];
		}
	}
	return *this;
}

double Matrix::wyznacznik() const{
	if (r!=c) throw size_err();

	Matrix m(*this);
	double det=1;

	for(uint k=0; k<r-1; ++k){
			if(m.data[c*k + k]==0) throw zero_err();
			
			for(uint i=k+1; i<r; ++i){
				m.data[c*i + k] /= m.data[c*k + k];
			}
			for(uint i=k+1; i<r; ++i){
				for(uint j=k+1; j<r; ++j){ 
					m.data[c*i + j] -= (m.data[c*i + k]*m.data[c*k + j]); 
				}}}
	for (uint i=0; i<c; ++i) det*=m.data[i*c+i];
	//m.rysuj();
	return det;
	}


bool Matrix::operator==(const Matrix& m) const{
	if (c!=m.c || r!=m.r) return 0;
	for (uint i=0; i<r; ++i){
		for (uint j=0; j<c; ++j){
			if (m.data[INDEX] != data[INDEX]) return 0;
		}
	}
	return 1;
}

bool Matrix::operator!=(const Matrix& m) const{
	return !(*this==m);
}


int main(){
	//przykladowe dzialania

	Matrix m1(6,6), m2(6,6), m3(1,2), m4(2,1);
	Matrix mw(3,3);

	try{
	m1.init(2);m2.init(3);m3.init(1.5);m4.init(5);
	
	m1(0,1,3);
	cout << (m1(1,1)) << endl;
	m1.transpozycja().rysuj();m2.rysuj();
	(m1+m2).rysuj();
	(m1-m2).rysuj();
	
	Matrix m5(m4*m3);
	
	m5(0,0,3);m5(1,1,1);
	m5.rysuj();
	
	printf("%lf\n",m5.wyznacznik());
	}


	catch(error){
		printf("ERR\t wrong matrix size!\n");
	}
	return 0;
}
