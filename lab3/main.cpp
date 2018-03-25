#include "Wektor.h"
#include <iostream>

using namespace std;

int main(){
	Wektor w(1,2,3);
	Wektor w2(2.5,6,11);

	
	cout << endl;
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