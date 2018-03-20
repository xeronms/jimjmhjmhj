#ifndef m_h
#define m_h

class Macierz{
	double *e;
	unsigned int r, c;

public:
	Macierz(unsigned int r_, unsigned int c_);
	~Macierz();
	Macierz(unsigned int r_, unsigned int c_, double, ...);
	void printm();
	Macierz operator+(Macierz);
	Macierz mnozenie_skalarne(double);
	Macierz mnozenie_macierzy(Macierz);
	Macierz transpozycja();
	bool porownanie(Macierz);

	
};



#endif