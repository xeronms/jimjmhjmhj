#include "Wektor.h"
#include <iostream>

using namespace std;


Wektor::Wektor(double a, double b, double c):x(a),y(b),z(c){}

Wektor::Wektor(Wektor& w):x(w.x),y(w.y),z(w.z){}


Wektor& Wektor::operator=(Wektor& w){
	x = w.x; y = w.y; z = w.z;
	return *this;
}

void Wektor::printv(){
	printf("%lf %lf %lf\n",x,y,z);
}

void Wektor::putv(double a, double b, double c){
	x = a; y = b; z = c;
}

Wektor Wektor::operator+(const Wektor &w2)const{
	return Wektor(x+w2.x, y+w2.y, z+w2.z);
}

Wektor Wektor::operator-(const Wektor& w)const {
	return *this+(w*(-1));
}

Wektor Wektor::operator*(double k)const{
	return Wektor(x*k, y*k, z*k);
}

double Wektor::operator*(const Wektor &w)const{
	return x*w.x+y*w.y+z*w.z;
}

Wektor Wektor::operator/(double k)const{
	if (!k) throw zero_devision();
	return (*this)*(1/k);
}

Wektor Wektor::iloczynW(const Wektor &w)const{
	return Wektor(y*w.z-z*w.y, z*w.x-x*w.z, x*w.y-y*w.x);
}

bool Wektor::operator==(const Wektor &w)const{
	return x==w.x && y==w.y && z==w.z;
}

bool Wektor::operator!=(const Wektor &w)const{
	return !(*this==w);
}

void Wektor::normalizacja(){
	double len = sqrt(x*x+y*y+z*z);
	*this = Wektor(x/len, y/len, z/len);
}



Wektor operator*(double k, Wektor w){
	return (w*k);
}


zero_devision::zero_devision(){printf("ERR\n");}