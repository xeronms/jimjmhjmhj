#include "Macierz.h"
#include <cstdarg>
#include <iostream>

Macierz::Macierz(unsigned int r_, unsigned int c_):r(r_),c(c_){
		e = new double[r_*c_];
	}

Macierz::~Macierz(){
	delete [] e;
	}

Macierz::Macierz(unsigned int r_, unsigned int c_, double a ...):r(r_),c(c_){
		e = new double[r_*c_];
		va_list arg;
		va_start (arg, a);
		for (int i=0; i<(r_*c_); ++i){
			e[i]=a;
			a = va_arg(arg, double);
		}
		va_end(arg);
	}

void Macierz::printm(){
	for (int i=0; i<r+c; ++i){
		std::cout << e[i] << "\t";
		if (!((i+1)%c)) std::cout << std::endl;
	}
}

Macierz Macierz::operator+(Macierz m){
	double a = e[0]+m.e[0];

	return m;

}

