#include <iostream>
#include <string>
#include <locale>

/*Program i�erisinde acil ��k�� kap�s� olu�tursun olu�turmas�n bir nedenden �t�r� private olan bir de�ere ula�mak istiyoruz bunun i�in
arkada� yani friends fonksiyonlar kullan�l�r. Bir arkada��n ile bir�eylerini payla��r gibi s�n�f i�erisindeki bir �ok �eyi yaplayabilir.
Fonksiyonun kullan�m �rne�ini yapal�m.*/

class test
{
	private:
		int x;
	public:
		int GET_X(){return x;}
		friend void SET_X(test &, int);
};

void SET_X(test &t, int inpx)
{t.x = inpx;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test *t1 = new test;
	SET_X(*t1, 12);
	std::cout << t1->GET_X() << std::endl;
	return 0;
}
