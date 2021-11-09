#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*
Const Nesneler;
	Sabit olarak tan�mlanan nesneler i�in sadece constructor metodu ve destructor metodu �a�r�l�r ve i�lmler yap�l�r. Farkl� bir
�ekilde nesnemizin hi� bir �zelli�ine s�n�f d��ar�s�ndan eri�emeyiz.

Const Metodlar;
	E�er bir metod const olarak belirtilir ise o metod i�erisinden s�n�f�n gi�bir �zelli�ine m�dahale veya de�i�tirme
uygulayamaz. Yani return std::cout gibi i�lemler yapabiliriz fakat this->x = val; �eklinde atama yapamay�z.
*/

int testvariable;

class test
{
	private:
		int x;
		int y;
	public:
		test(int, int);
		void SET_VALUE(int, int);
		/*Burada getter metodlar�nda sadece d��ar�ya de�er d�nderebilir olmas� gerekir yani bir de�eri set edememesi gerekir.*/
		int GET_X()const{testvariable = 8; /*S�n�f d���ndaki de�er de�i�tirildi.*/ return x;}
		int GET_Y()const{/*x = val; yapam�yoruz fakat s�n�f d���ndaki bir de�i�ken de�eri de�i�tirilebilir.*/ return y;}
};

test::test(int x = 0, int y = 0) : x(x), y(y)
{std::cout << "Constructor �al��t� de�erler: " << this->x << ", " << this->y << std::endl;}

void test::SET_VALUE(int x = 0, int y = 0){this->x = x; this->y = y;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	testvariable = 0;
	const test t1(3, 2);
	test t2;
	t2.SET_VALUE(8, 9);
	std::cout << "testvariable = " << testvariable << std::endl;
	t2.GET_X(); /*Burada testvariable de�i�keni de�i�tirildi.*/
	std::cout << "testvariable = " << testvariable << std::endl;
	/*Bu noktada t1 tan�mland�ktan sonra ne get ne set hi�bir metod ve �zellik tekrardan �al��t�r�lamaz.*/
	std::cout << "t2 i�in de�erler: " << t2.GET_X() << ", "	<< t2.GET_Y() << std::endl;
	return 0;
}

