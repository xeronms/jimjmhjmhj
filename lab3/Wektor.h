#ifndef w_h
#define w_h
#include <iostream>

class Wektor{
	double x,y,z;
public:
	Wektor(double a=0, double b=0, double c=0);

	
	void printv();
	Wektor operator+(const Wektor&)const;
	Wektor operator-(const Wektor&)const;//
	Wektor operator*(double)const;
	double operator*(const Wektor&)const;
	Wektor operator/(const Wektor&)const;//
	Wektor iloczynW(const Wektor&)const;
	bool operator==(const Wektor&)const;
	bool operator!=(const Wektor&)const;
	void normalizacja();


};

Wektor operator*(double, Wektor);
Wektor operator/(double, Wektor);//
#endif