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
	for (unsigned int j=0; b; ++j){
		++len;
		b /= 10;
	}
	dig = new char [len];

	for (unsigned int i=2; a; ++i){
		dig[len - i] = (a % 10) + 48;
		a /= 10;
	}
	dig[len -1] = '\0';
}

BigInt::BigInt(bool p, unsigned int l):len(l),positive(p){
	dig = new char [len];
}

BigInt::BigInt(char* a){
	if (a[0] == '-'){
		positive = 0;
		len = strlen(a);
		dig = new char [len];
		strcpy(dig, a+1);
	}
	else{
		positive = 1;
		len = strlen(a) + 1;
		dig = new char [len];
		strcpy(dig, a);
	}
}

BigInt::BigInt(const BigInt& a){
	len=a.len; positive = a.positive;
	dig = new char [a.len];
	memcpy(dig, a.dig, a.len*sizeof(char));
}

BigInt::~BigInt(){
	delete [] dig;
}


//BigInt& BigInt::operator=(const BigInt a){}

unsigned char BigInt::operator[](unsigned int i) const{
	return this->dig[this->len - (2+i)];
}

bool BigInt::operator==(const BigInt& a) const{
	if (  len != a.len ) return 0;
	for ( unsigned int i = 0; i < len-1; ++i ){
		if ( dig[i] != a.dig[i] ) return 0;
	}
	return 1;
}
bool BigInt::operator!=(const BigInt& a) const{
	return !(*this==a);
}
bool BigInt::operator>(const BigInt& a) const{
	if (  len < a.len ) return 0;
	if (  len > a.len ) return 1;
	for ( unsigned int i = 0; i < len-1; ++i ){
		if ( dig[i] < a.dig[i] ) return 0;
		if ( dig[i] > a.dig[i] ) return 1;
	}
	return 0;
}
bool BigInt::operator<(const BigInt& a) const{
	return a>*this;
}
bool BigInt::operator>=(const BigInt& a) const{
	return !(*this<a);
}
bool BigInt::operator<=(const BigInt& a) const{
	return !(*this>a);
}


BigInt BigInt::operator+(const BigInt& a) const{
	if ( len < a.len ) return a+*this; // here I assume len >= a.len

	if (positive&&!a.positive) return *this-(-a);
	else if(!positive&&a.positive) return a-(-*this);

	BigInt b( 1 ,len+2 );
	char tmp = 0;

	if(!positive&&!a.positive) b.positive=0;

	for ( unsigned int i = 0; i < a.len-1; ++i ){
		b.dig[i] = ((dig[i] + a.dig[i] + tmp) % 10);
		tmp = (dig[i] + a.dig[i] + tmp) / 10;
	}
	if ( len == a.len ) b.dig[len-1]=tmp;
	else {
		for ( unsigned int i = 0; i < len-1; ++i){
			b.dig[i] = ((dig[i] + tmp) % 10);
			tmp = (dig[i] + tmp) / 10;
		}
	}
	b.dig[ len - 1] = tmp;
	b.dig[ len ] = '\0';
	return b;
}

BigInt BigInt::operator-(const BigInt& a) const{
	if ( len < a.len || ( len == a.len && *this < a )) return -(a-*this);

	if (positive&&!a.positive) return *this+(-a);
	else if(!positive&&a.positive) return a+(-*this);

	BigInt b( 1 ,len+2 );
	char tmp;

	if(!positive&&!a.positive) b.positive=0;



	return b;


}

BigInt BigInt::operator-() const{
	BigInt a(*this);
	a.positive = !positive;
	return a;
}


//ew moge zrobic tak ¿e BigInt b( buf.size ) i potem a = b ale nwm czy tak mozna
std::istream& operator>>(std::istream& is, BigInt& a){
	std::string buf;
	unsigned int prev_a_len = a.len;

	is >> buf;

	if ( buf.front() == '-' ){
		a.positive = 0;
		buf.erase(0);
	}
	else a.positive = 1;
	a.len = buf.size()+1;

	// if len < size
	// THROW BUFF SIZE ERROR
	
	for ( unsigned int i = 0; i < a.len - 1; ++i){
		a.dig[i] = buf[i];
		printf("%c\t",buf[i]);
	}

	for ( unsigned int i = a.len - 1; i < prev_a_len ; ++i){
		a.dig[i] = '\0';
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const BigInt& a){
	unsigned int i = 0;
	if(!a.positive) os << '-';
	while( a.len - (i+1) ){
		os << a.dig[i];
		++i;
	}
	 os << std::endl;
	 return os;
}

int main(){
	BigInt a("123");
	BigInt b(290);
	BigInt c(b);
	BigInt d(1);

	//std::cin >> d;
	//std::cout << a[16] << '\t' << std::endl;
	std::cout << a << b << c << (b+c) <<std::endl;
	return 0;
}