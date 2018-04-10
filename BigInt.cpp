#include "BigInt.h"
#include <iostream>
#include <math.h>
#include <string>
#include <cctype>


BigInt::BigInt(int a = 0){
	if (a>=0) positive = 1;
	else {
		positive = 0;
		a *= -1;
	}

	int b = a;
	len = 1;
	// how long the integer is
	for (unsigned int j=0; b; ++j){
		++len;
		b /= 10;
	}
	num = new char [len];

	for (unsigned int i=2; a; ++i){
		num[len - i] = (a % 10) + 48;
		a /= 10;
	}
	num[len -1] = '\0';
}

BigInt::BigInt(char* a){
	if (a[0] == '-'){
		positive = 0;
		len = strlen(a);
		num = new char [len];
		strcpy(num, a+1);
	}
	else{
		positive = 1;
		len = strlen(a) + 1;
		num = new char [len];
		strcpy(num, a);
	}
}

BigInt::BigInt(const BigInt& a){
	len=a.len; positive = a.positive;
	num = new char [a.len];
	memcpy(num, a.num, a.len*sizeof(char));
}

BigInt::~BigInt(){
	delete [] num;
}


unsigned char BigInt::operator[](unsigned int i) const{
	return this->num[this->len - (2+i)];
}




std::istream& operator>>(std::istream& is, BigInt& a){
	delete [] a.num;
	std::string buf;

	is >> buf;

	if ( buf.front() == '-' ){
		a.positive = 0;
		buf.erase(0);
	}
	else a.positive = 1;
	a.len = buf.size();
	strcpy(a.num,buf.data());


	return is;
}

std::ostream& operator<<(std::ostream& os, const BigInt& a){
	unsigned int i = 0;
	if(!a.positive) os << '-';
	while( a.num[i] != '\0'){
		os << a.num[i];
		++i;
	}
	 os << std::endl;
	 return os;
}

int main(){
	BigInt a("-124369512347032890465290583910294852306985702589310975130982563895328903528093529803529850328903592171231281234578469035699");
	BigInt b(-39290);
	BigInt c(b);
	BigInt d;

	std::cin >> d;
	std::cout << a[16] <<std::endl;
	std::cout << a << b << c << d <<std::endl;
	return 0;
}