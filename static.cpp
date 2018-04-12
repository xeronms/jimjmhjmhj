#include <iostream>


class A{
	static unsigned int no;

public:
	static void incNo(){
		++no;
		std::cout << no << std::endl; 
		// nie ma skad wziac *this, nie moze uzywac niestatycznych funkcji klasy
	}
	
	A () {
		incNo();
		// if no>3 throw exception
	}
	
	~A () {
		--no;
		std::cout << no << std::endl; 
	}
	
	A(const A& a){
		incNo();
	}
	

};
unsigned int A::no = 0;

int main(){
	
	A a1, a2;
	//A a3 = a1; to samo co a3(a1)	
	A *tab[10];
	//A tab[10]; tworzy 10 obiektow
	
	a1.incNo(); // robi to samo co A::incNo(); f statyczxna wywoluje sie na klasie a nie na obiekcie
	
	return 0;
}