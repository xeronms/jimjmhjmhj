#ifndef bigint_h
#define bigint_h
#include <iostream>

class BigInt{
	char * dig;
	unsigned int len;
	// len = numbers of digits + '\0'
	bool positive; 

	void check_length();

public:
	BigInt(long);
	BigInt(char*);
	BigInt(bool, unsigned int);
	BigInt(const BigInt&);
	~BigInt();
	BigInt& operator=(const BigInt&);

	unsigned char operator[](unsigned int) const;
	BigInt operator+(const BigInt&) const;
	BigInt operator-(const BigInt&) const;
	BigInt operator-() const;
	BigInt operator*(const BigInt&) const;

	BigInt operator+(long) const;
	BigInt operator-(long) const;
	BigInt operator*(long) const;

	BigInt operator++() const;
	BigInt operator--() const;

	bool operator==(const BigInt&) const;
	bool operator!=(const BigInt&) const;
	bool operator>(const BigInt&) const;
	bool operator<(const BigInt&) const;
	bool operator>=(const BigInt&) const;
	bool operator<=(const BigInt&) const;


	friend std::istream& operator>>(std::istream&, BigInt&);
	friend std::ostream& operator<<(std::ostream&, const BigInt&);
};

BigInt operator+(long, const BigInt&);
BigInt operator-(long, const BigInt&);
BigInt operator*(long, const BigInt&);

#endif