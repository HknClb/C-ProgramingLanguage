#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include "test.h" /*kendi k�t�phanemizi include ediyoruz.*/

/*Class Libary:
	Biz bu not k�sm�nda s�rekli olarak bir test s�n�f�n� tekrar tekrar tan�ml�yoruz bunun yerine bir libary olu�turarak ordan
eri�im sa�amay� g�sterelim.
	�ncelikle bir libary kullan�rken e�er sadece tan�mlama var ise direkt olarak .h uzant�l� bir k�t�phane olu�turulur e�er 
bunun i�erisinde fonksiyonlar da var ise fonksiyonlar� da bir cpp dosyas�na kaydetmemiz gerekir.


class test
{
	private:
		int x;
		int y;
		int *ptr;
		const int cs;
	public:
		test(int, int, int, int);
		test(test &);
		~test()
		{
			std::cout << "Destructor �al��t� !\nDe�erler: " << x << ", " << y << ", " << *ptr << ", " << cs << std::endl;
			delete ptr;
		}
		void SET_VALUE(int, int, int);
		int GET_X(){return x;}
		int GET_Y(){return y;}
		int GET_PTR(){return *ptr;}
		int GET_CS(){return cs;}	
};

test::test(int x = 0, int y = 0, int ptr = 0, int cs = 0) : x(x), y(y), cs(cs)
{
	this->ptr = new int(ptr);
	std::cout << "Constructor �al��t� !\nDe�erler: " << this->x << ", " << this->y << ", " << *(this->ptr) << ", " << this->cs
	<< std::endl;
}

test::test(test &t) : x(t.x), y(t.y), cs(t.cs)
{
	this->ptr = new int((*(t.ptr)));
	std::cout << "Copy Constructor �al��t� !\nDe�erler: " << this->x << ", " << this->y << ", " << *(this->ptr) << ", "
	<< this->cs << std::endl;
}

void test::SET_VALUE(int x, int y, int ptr)
{this->x = x; this->y = y; *(this->ptr) = ptr;}
*/

int main()
{
	setlocale(LC_ALL, "Turkish");
	test t1(25, 23, 45, 58);
	std::cout << "t1 i�in\nx: " << t1.GET_X() << "\ny: " << t1.GET_Y() << "\nptr: " << t1.GET_PTR() << "\ncs: " << t1.GET_CS()
	<< std::endl;
	test t2(t1);
	std::cout << "t2 i�in\nx: " << t2.GET_X() << "\ny: " << t2.GET_Y() << "\nptr: " << t2.GET_PTR() << "\ncs: " << t2.GET_CS()
	<< std::endl;
	test t3;
	t3.SET_VALUE(5, 8, 45);
	std::cout << "t3 i�in\nx: " << t3.GET_X() << "\ny: " << t3.GET_Y() << "\nptr: " << t3.GET_PTR() << "\ncs: " << t3.GET_CS()
	<< std::endl;
	test t4(1, 2, 3);
	std::cout << "t4 i�in\nx: " << t4.GET_X() << "\ny: " << t4.GET_Y() << "\nptr: " << t4.GET_PTR() << "\ncs: " << t4.GET_CS()
	<< std::endl;
	return 0;
}
