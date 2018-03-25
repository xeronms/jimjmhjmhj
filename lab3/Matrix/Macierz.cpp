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



class Macierz{
	double *macierz;
	unsigned int r, c;

public:
	Macierz(unsigned int r_,unsigned int c_):r(r_),c(c_){
		macierz = new double [r_*c_];
}
	Macierz(const Macierz &m):r(m.r),c(m.c){
		macierz = new double [r*c];
		memcpy(macierz, m.macierz, r*c*sizeof(double));
}
	~Macierz(){
		delete [] macierz;
}
	Macierz &operator=(const Macierz &m){
		r = m.r; c = m.c;
		delete [] macierz;
		macierz = new double [r*c];
		memcpy(macierz, m.macierz, r*c*sizeof(double));
		return *this;
}

	void init(double);
	void rysuj() const;
	double podaj_element(uint a, uint b) const;
	Macierz zmien_element(uint a, uint b, double val);
	Macierz operator+(const Macierz&) const;
	Macierz operator-(const Macierz&) const;
	Macierz operator-() const;
	Macierz operator*(double) const;
	Macierz operator*(const Macierz&) const;
	Macierz transpozycja();
	double wyznacznik() const;
	bool operator==(const Macierz&) const;
	bool operator!=(const Macierz&) const;
};
Macierz operator*(double, const Macierz&);




void Macierz::init(double a){
		for (uint i=0; i<r*c; ++i){
			macierz[i]=a;
		}
}

void Macierz::rysuj() const{
	for (uint i=0; i<(r*c); ++i){
		std::cout << macierz[i] << "\t";
		if (!((i+1)%c)) std::cout << std::endl;
	}
	std::cout << std::endl;
}

double Macierz::podaj_element(uint i, uint j) const{
	return macierz[INDEX];
}

Macierz Macierz::zmien_element(uint i, uint j, double val){
	 macierz[INDEX] = val;
	 return *this;
}

Macierz Macierz::operator+(const Macierz& m) const{
	if (r!=m.r || c!=m.c) throw size_err();
	Macierz m2(r,c);

	for (uint i=0; i<r*c; ++i){
		m2.macierz[i] = m.macierz[i] + macierz[i];
	}
	return m2;
}

Macierz Macierz::operator-() const{
	return (*this)*(-1);
}

Macierz Macierz::operator-(const Macierz& m) const{
	return *this + (-m);

}

Macierz Macierz::operator*(double k) const{
	Macierz m(r,c);
	for (uint i=0; i<r*c; ++i){
		m.macierz[i] = macierz[i] * k; 
	}
	return m;
}


Macierz Macierz::operator*(const Macierz& m) const{
	if (c!=m.r) throw size_err();
	Macierz m2(r,m.c);
	for (uint i=0; i<r; ++i){
		for (uint j=0; j<m.c; ++j){
			m2.macierz[i*m.c+j] = 0;
			for (uint k=0; k<c; ++k){
				m2.macierz[i*m.c+j] += macierz[i*c+k]*m.macierz[m.c*k+j]; //??????????????
			}
		}
	}
	return m2;
}

Macierz operator*(double k, const Macierz& m){
	return m*k;
}


Macierz Macierz::transpozycja(){
	Macierz m(*this);
	for (uint i=0; i<r; ++i){
		for (uint j=0; j<c; ++j){
			macierz[INDEX] = m.macierz[j*r+i];
		}
	}
	return *this;
}

double Macierz::wyznacznik() const{
	if (r!=c) throw size_err();

	Macierz m(*this);
	double det=1;

	for(uint k=0; k<r-1; ++k){
			if(m.macierz[c*k + k]==0) throw zero_err();
			
			for(uint i=k+1; i<r; ++i){
				m.macierz[c*i + k] /= m.macierz[c*k + k];
			}
			for(uint i=k+1; i<r; ++i){
				for(uint j=k+1; j<r; ++j){ 
					m.macierz[c*i + j] -= (m.macierz[c*i + k]*m.macierz[c*k + j]); 
				}}}
	for (uint i=0; i<c; ++i) det*=m.macierz[i*c+i];
	//m.rysuj();
	return det;
	}


bool Macierz::operator==(const Macierz& m) const{
	if (c!=m.c || r!=m.r) return 0;
	for (uint i=0; i<r; ++i){
		for (uint j=0; j<c; ++j){
			if (m.macierz[INDEX] != macierz[INDEX]) return 0;
		}
	}
	return 1;
}

bool Macierz::operator!=(const Macierz& m) const{
	return !(*this==m);
}


int main(){
	//przykladowe dzialania

	Macierz m1(6,6), m2(6,6), m3(1,2), m4(2,1);
	Macierz mw(3,3);

	try{
	m1.init(2);m2.init(3);m3.init(1.5);m4.init(5);
	
	m1.zmien_element(0,1,3);
	cout << (m1.podaj_element(1,1)) << endl;
	m1.transpozycja().rysuj();m2.rysuj();
	(m1+m2).rysuj();
	(m1-m2).rysuj();
	
	Macierz m5(m4*m3);
	
	m5.zmien_element(0,0,3);m5.zmien_element(1,1,1);
	m5.rysuj();
	
	printf("%lf\n",m5.wyznacznik());
	}


	catch(error){
		printf("ERR\t wrong matrix size!\n");
	}
	return 0;
}
