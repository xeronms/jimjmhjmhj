#include "iostream"
/* zadanie - rozdział 15 (bitable)

rti - run time indentification - mechanizm pokazujacy nam dany typ wskaznika(mechanbizm identyfikacji typow)
żeby działał to typ powinien miec przynajmniej jedna funkcję wirtualną (np destruktor)

bit mapy:
czytanie z pliku po linijce, np
	c 10 10 7 200 100 235
	circle,wymiary,rgb
	r 23 23 4
	rectangle
	l
	linia
	# komentarz ktory pomijamy
jednowyrazowe komendy do wykonywania

z arg maina odczytac scieżkę pliku

tworzymy ifstream
string str;
getline(str,);
i string stream is(str) //strumien ktory pisze do stringa, 
char cmd;
is >> cmd;
switchcase{
	is >> x>>y>>R>>r>>g>>b

*/ 


class Ptak{
public:
	virtual void lec(){
		std::cout << "jestem ptak i lece..." << std::endl;
	}
};

class Pingwin : public Ptak{
public:
	void lec(){
		std::cout << "jestem ptak i nie umiem leciec" << std::endl;
	}
};

class MalyPingwin : public Pingwin{
public:
	void lec(){
		std::cout << "jestem ptak i nie umiem leciec bo jestem maly" << std::endl;
	}
}; 

int main(){
	Ptak a1;
	Pingwin b1;
	MalyPingwin c1;
	
	a1.lec();
	b1.lec();
	c1.lec();
	
	// a1=c1; pingwin zostanie przypisany jako ptak (wszystkie dodatkowe pola pingwina, różne od ptaka, zostaną pominięte)
	Ptak *a2, *a3, *a4;
	//a2 = (Pingwin*)&a1; // dodatkowe pola będą puste( dostaniemy śmiec) nie robimy tak!!
	// żeby tak zrobić to robimy dynamic cast, WYKŁAD DYNAMIC CAST
	a2 = &a1;
	a3 = &b1;
	a4 = &c1;
	// brane jest pod uwage jakiego typu jest wsk/ref a nie jaki jest prawdziwy typ (jesli lec() nie jest wirtualna)
	// gdy mamy f wirtualna to zachowuje sie w sposob polimorficzny
	a2->lec();
	a3->lec();
	a4->lec();
	
	std::cout << sizeof(Ptak) << std::endl;
	
	return 0;
}
