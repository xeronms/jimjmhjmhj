#include<iostream>


/* zad:
 * poprawa ojb
 * konterenry będące szablonami: stos dynamiczny na szablon (szablon klasy)
 * na innych kontenerach: lista jednokier, lista dwukier, zbiór(set): czyli gdy raz coś wrzucamy to już się nie dodaje
*/
//deklaracja klasy
template<typename T, int SIZE>
class Stos{
public:
	Stos():top(0){
		x = T(); // inicjalizacja zerowa, można w szablonach. dla typow prostych ustawiamy neutralne wartości. np dla bool,int 0
		// lub :x(T())
	}
	
	
	void push(const T& e){
		elements[top++]=e;	
	}
	
	T pop(){ // biblioteczna f pop nic nie zwraca, a funkcja top pokazuje tylko co jest na gorze, ale nie usuwa
	return elements[--top];
}
	
	bool isEmpty() const {
		return !top;
	}
	
private:
	T elements[SIZE];
	unsigned int top;
	T x; // przyklad
};





int main(){
	int const a =100;
	
	Stos<int,a> si;
	Stos<double,2000> sd;
	//Stos<Pingwin> sp;

	
	return 0;
}