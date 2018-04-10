#ifndef bigint_h
#define bigint_h
#include <iostream>

class BigInt{
	char * num;
	unsigned int len;
	bool positive; 

public:
	BigInt(int);
	BigInt(char*);
	BigInt(const BigInt&);
	~BigInt();
	BigInt& operator=(const BigInt);

	unsigned char operator[](unsigned int) const;
	BigInt operator+(const BigInt&) const;

	friend std::istream& operator>>(std::istream&, BigInt&);
	friend std::ostream& operator<<(std::ostream&, const BigInt&);
};


#endif