#include "Wektor.h"
#include "Macierz.h"
#include <iostream>

using namespace std;

int main(){
	Wektor w(1,2,3);
	Wektor w2(2.5,6,11);
	Macierz m(2,2);
	Macierz m2(2,2, 1.0, 2.0, 3.0, 4.0,1.1);

	m2.printm();

	w.printv();
	(w2).printv();
	(w+w2).printv();
	(w*4).printv();
	(4*w).printv();
	w.iloczynW(w2).printv();
	cout << w*w2 << endl;
	cout << (w==w2) << endl;
	cout << (w!=w2) << endl;
	w.normalizacja();
	w.printv();
	
	return 0;
}