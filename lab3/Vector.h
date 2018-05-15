#ifndef w_h
#define w_h

class Vector{
	double x,y,z;
public:
	Vector(double a=0, double b=0, double c=0);
	Vector(Vector&);

	Vector& operator=(Vector&);
	void printv();
	void putv(double, double, double);
	Vector operator+(const Vector&)const;
	Vector operator-(const Vector&)const;
	Vector operator*(double)const;
	double operator*(const Vector&)const;
	Vector operator/(double k)const;
	Vector iloczynW(const Vector&)const;
	bool operator==(const Vector&)const;
	bool operator!=(const Vector&)const;
	void normalizacja();


};

class zero_devision{
public:
	zero_devision();
};

Vector operator*(double, Vector);
#endif