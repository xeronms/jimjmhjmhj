#include<iostream>
#include <stdio.h>
#include<string.h>
//szablony funkcji

/*
double min(double a, double b){
	return a<b?a:b;
}
int min(int a, int b){
	return a<b?a:b;
}
*/


//szablon<typ TYP> //korespondencja seryjna 
template<typename T>
T min(T a, T b){
	return a<b?a:b;
}


/* można ale w tym przypadku bez sensu
template<typename T, typename S>
T min(T a, S b){
	return a<b?a:b;
}
*/

char* min(char* a, char* b){
	std::cout << "Werja Specjalna" << std::endl;
	
	return strcmp(a,b)<0?a:b;
}


int main(){
	int a = 3, b=-7, c;
	double x=-17,y=20,z;
	//c=static_cast<int>(::min(a,b));
	c=::min(a,b);
	//! c=::min(a,x); nie zna;lz
	c=::min(static_cast<double>(a),x);
	// dwa dwukropki :: znaczy przestrzeń globalną
	// gdyby ktoś napisał using namespace std, to wywoła funkcji z std, a tak to wywołuje z przestrzeni globalnej
	
	//jawne przekazanie typu T
	c=::min<int>(a,x);
	
	z=::min(x,y);
	char r =min('a','b');
	// porownujemy wskazniki 
	std::cout << min("Ala","Olasd") << std::endl;

	return 0;
}
