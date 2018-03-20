#ifndef w_h
#define w_h
#include <iostream>

class Wektor{
	double x,y,z;
public:
	Wektor(double a=0, double b=0, double c=0);
	
	void printv();
	Wektor operator+(Wektor)const;
	Wektor operator*(double)const;
	double operator*(Wektor)const;
	Wektor iloczynW(Wektor)const;
	bool operator==(Wektor)const;
	bool operator!=(Wektor)const;
	void normalizacja();


};

Wektor operator*(double, Wektor);

#endif