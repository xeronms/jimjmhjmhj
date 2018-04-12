#include <iostream>


class A{
	static unsigned int no;

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
	
	static A* instance;
	
public:
	static A& getInstance(){
		if (!instance){
			/* lub
			static A a;
			*instance = a;
			*/
			instance = new A();
		}
			return *instance;
	}
	

};

unsigned int A::no = 0;
A*A::instance = 0; // jesli chcemy miec od razu instancja to tutaj przypisujemy

int main(){
	
	//A*A::instance = 
	A& ref = A::getInstance();
	A& ref2 = A::getInstance();
	
	
	return 0;
}