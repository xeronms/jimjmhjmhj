#include "Vector.h"
#include <iostream>

using namespace std;


Vector::Vector(double a, double b, double c):x(a),y(b),z(c){}

Vector::Vector(Vector& w):x(w.x),y(w.y),z(w.z){}


Vector& Vector::operator=(Vector& w){
	x = w.x; y = w.y; z = w.z;
	return *this;
}

void Vector::printv(){
	printf("%lf %lf %lf\n",x,y,z);
}

void Vector::putv(double a, double b, double c){
	x = a; y = b; z = c;
}

Vector Vector::operator+(const Vector &w2)const{
	return Vector(x+w2.x, y+w2.y, z+w2.z);
}

Vector Vector::operator-(const Vector& w)const {
	return *this+(w*(-1));
}

Vector Vector::operator*(double k)const{
	return Vector(x*k, y*k, z*k);
}

double Vector::operator*(const Vector &w)const{
	return x*w.x+y*w.y+z*w.z;
}

Vector Vector::operator/(double k)const{
	if (!k) throw zero_devision();
	return (*this)*(1/k);
}

Vector Vector::iloczynW(const Vector &w)const{
	return Vector(y*w.z-z*w.y, z*w.x-x*w.z, x*w.y-y*w.x);
}

bool Vector::operator==(const Vector &w)const{
	return x==w.x && y==w.y && z==w.z;
}

bool Vector::operator!=(const Vector &w)const{
	return !(*this==w);
}

void Vector::normalizacja(){
	double len = sqrt(x*x+y*y+z*z);
	*this = Vector(x/len, y/len, z/len);
}



Vector operator*(double k, Vector w){
	return (w*k);
}


zero_devision::zero_devision(){printf("ERR\n");}