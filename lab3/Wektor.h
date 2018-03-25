#ifndef w_h
#define w_h

class Wektor{
	double x,y,z;
public:
	Wektor(double a=0, double b=0, double c=0);
	Wektor(Wektor&);

	Wektor& operator=(Wektor&);
	void printv();
	void putv(double, double, double);
	Wektor operator+(const Wektor&)const;
	Wektor operator-(const Wektor&)const;
	Wektor operator*(double)const;
	double operator*(const Wektor&)const;
	Wektor operator/(double k)const;
	Wektor iloczynW(const Wektor&)const;
	bool operator==(const Wektor&)const;
	bool operator!=(const Wektor&)const;
	void normalizacja();


};

class zero_devision{
public:
	zero_devision();
};

Wektor operator*(double, Wektor);
#endif