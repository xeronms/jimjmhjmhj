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
	len = 0;
	for (unsigned int j=0; b; ++j){
		++len;
		b /= 10;
	}
	dig = new char [len];

	for (unsigned int i=0; a; ++i){
		dig[i] = (a % 10);
		a /= 10;
	}
}

BigInt::BigInt(bool p, unsigned int l):len(l),positive(p){
	dig = new char [len];
}

BigInt::BigInt(char* a){
	if (a[0] == '-'){
		positive = 0;
		len = strlen(a)-1;
		dig = new char [len];
		for ( unsigned int i=0; i < len; ++i){
			dig[i] = (a[len-i]-48);
		}
	}
	else{
		positive = 1;
		len = strlen(a);
		dig = new char [len];
		for ( unsigned int i=0; i < len; ++i){
			dig[i] = (a[len-i-1]-48);
		}
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
	return this->dig[i];
}

bool BigInt::operator==(const BigInt& a) const{
	if (  len != a.len ) return 0;
	for ( unsigned int i = 0; i < len; ++i ){
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
	for ( unsigned int i = 0; i < len; ++i ){
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

	BigInt b( 1 ,len+1 );
	char tmp = 0;

	if(!positive&&!a.positive) b.positive=0;

	for ( unsigned int i = 0; i < a.len; ++i ){
		b.dig[i] = ((dig[i] + a.dig[i] + tmp) % 10);
		tmp = (dig[i] + a.dig[i] + tmp) / 10;
	}
	for ( unsigned int i = a.len; i < len; ++i){
		b.dig[i] = ((dig[i] + tmp) % 10);
		tmp = (dig[i] + tmp) / 10;
	}

	if (tmp) b.dig[ len ] = tmp;
	else --b.len;

	return b;
}

BigInt BigInt::operator-(const BigInt& a) const{
	if ( len < a.len || ( len == a.len && *this < a )) return -(a-*this);

	if (positive&&!a.positive) return *this+(-a);
	else if(!positive&&a.positive) return a+(-*this);

	BigInt b( 1 ,len );
	char tmp = 0;

	if(!positive&&!a.positive) b.positive=0;

	for ( unsigned int i = 0; i < a.len; ++i ){
		b.dig[i] = dig[i] - (a.dig[i] + tmp);
		if ( b.dig[i] < 0){
			b.dig[i] += 10;
			tmp = 1;
		}
		else tmp = 0;
	}
	for ( unsigned int i = a.len; i < len; ++i){
		b.dig[i] = dig[i] - tmp;
		if ( b.dig[i] < 0){
			b.dig[i] += 10;
			tmp = 1;
		}
		else tmp = 0;
	}

	//sprawdzamy czy len nie jest za dlugie
	b.check_length();

	return b;
}

BigInt BigInt::operator-() const{
	BigInt a(*this);
	a.positive = !positive;
	return a;
}

BigInt BigInt::operator*(const BigInt& a) const{
	//if ( len < a.len ) return a**this; // here I assume len >= a.len

	BigInt b( 1 ,len+a.len );
	char tmp = 0; unsigned int index;
	for ( unsigned int i = 0 ; i < b.len; ++b.len) b.dig[i]=0;
	
	if (positive&&!a.positive) b.positive=0;
	else if (!positive&&a.positive) b.positive=0;

	for ( unsigned int j = 0; j < a.len; ++j ){
		index = j;
		for ( unsigned int i = 0; i < len; ++i ){
			b.dig[index] += ((dig[i] * a.dig[j] + tmp) % 10);
			tmp = (dig[i] * a.dig[j] + tmp) / 10;
			++index;
		}
		b.dig[index] += tmp;
	}
	//b.check_length();

	return b;
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
	a.len = buf.size();

	// if len < size
	// THROW BUFF SIZE ERROR
	
	for ( unsigned int i = 0; i < a.len; ++i){
		a.dig[i] = buf[i];
		printf("%c\t",buf[i]);
	}

	/*for ( unsigned int i = a.len - 1; i < prev_a_len ; ++i){
		a.dig[i] = '\0';
	}*/
	return is;
}

std::ostream& operator<<(std::ostream& os, const BigInt& a){
	if(!a.positive) os << '-';
	for (int i = a.len-1; i>=0; --i){
		os << char(a.dig[i] + 48);
	}
	//std::string b = a.dig;
	 os << std::endl;
	 return os;
}

int main(){
	BigInt a("-13");
	BigInt b(290);
	BigInt c(b);
	BigInt d(3);
	BigInt e(6);
	//std::cin >> d;
	std::cout << (a==b) << (d<c) <<'\t' << std::endl;
	std::cout << a << b << c << d << (b+c) << a-d << e-d << b-c << e*d << std::endl;
	return 0;
}


void BigInt::check_length(){
	for ( int i = len-1; i>0; --i){
		if (dig[i]) break;
		--len;
	}
}