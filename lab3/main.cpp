#include "Vector.h"
#include <iostream>

using namespace std;

int main(){
	Vector w(1,2,3);
	Vector w2(2.5,6,11);

	//przykladowe dzialania

	try{
	cout << endl;
	w.printv();
	(w2).printv();
	(w+w2).printv();
	(w-w2).printv();
	(w*4).printv();
	(3*w).printv();
	w.iloczynW(w2).printv();
	cout << w*w2 << endl;
	cout << (w==w2) << endl;
	cout << (w!=w2) << endl;
	w.normalizacja();
	w.printv();
	(w/0).printv();
	}
	catch(zero_devision){}

	return 0;
}