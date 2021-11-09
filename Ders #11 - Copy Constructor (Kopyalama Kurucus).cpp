#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Copy Consturctor;
	Bu constructor bir class dan t�retilen nesnedeki �zellikleri di�er bir nesneye ta��yabilmemizi sa�lar. Default olarak class
tan�mlamas�nda bir copy constructor vard�r fakat class i�erisinde pointer bir �zellik de�i�ken kullan�r isek burada hata verir.
�rne�in;
class test
{
	private:
		int *x;
}
�eklinde bir s�n�f�m�z olsun ve test t1; test t2; �eklinde iki adet s�n�f�m�z olsun. x i�in ram de yer ayr�lm�� olsun ve de�er
olarak 5 at�lm�� olsun copy constructor �al��t��� anda yani
t1 = t2; veya t1(t2); yap�ld��� anda *(this->x) = *(t2.x) olur ve bu durumda bu nesne i�in x de yer ayr�lmad��� i�in t2 nin
x pointer�n� kullan�r. Bu durumda e�er constructor i�erisinde delete kullan�r isek ilk olarak ilk nesnenin sonra ise di�er
nesnenin x pointer � i�in ram de ayr�lan yer silinir. �lk olarak silindi�i i�in ikinci olarak silinemez ve program hata verir.
	Copy Consturtor Tan�mlamas�:
test(test & veya test *) �eklinde tan�mlan�r fakat bunlar�n ba�lar�nda const olmas� gerekir ��nk� kopyalama s�ras�nda kopyalanan
nesne �zerinde de�i�iklik yap�lmamas� gerekir.
*/

class test2
{
	public:
		int x;
		test2(int);	
};

test2::test2(int x) : x(x){}

class test
{
	private:
		int x;
		int *ptr;
	public:
		test(int, int);
		test(test &);
		test(test2 &);
		~test(){std::cout << "Destructor �al��t� !\nDe�erler: " << x << ", " << *ptr << std::endl; delete ptr;}
		void SET_VALUE(int, int);
};

test::test(int x = 0, int ptr = 0)
{
	this->ptr = new int(ptr); this->x = x; 
	std::cout << "Constructor �al��t� !\nDe�erler: " << this->x << ", " << *(this->ptr) << std::endl;
}

test::test(test &t)
{
	this->ptr = new int(*(t.ptr)); this->x = t.x;
	std::cout << "Copy Constructor �al��t� !\nDe�erler: " << this->x << ", " << *(this->ptr) << std::endl;
}

test::test(test2 &t)
{
	this->x = t.x; this->ptr = new int(-5);
	std::cout << "Test2 Copy Constructor �al��t� !\nDe�erler: " << this->x << ", " << *(this->ptr) << std::endl;	
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test t1(35, 48);
	test t2 = t1;
	test2 t3(11);
	test t4(t3);
	return 0;
}

