#include <iostream>
#include <string>
#include <locale>
class test_b; /*test_a s�n�f� i�erisinde friend tan�mlamas� yapaca��m�z i�in yukar�s�nda tan�mlamak zorunday�z.*/

class test_a
{
	private:
		int x;
	public:
		int GET_X(){return x;}
		friend void SET_X(test_a &, int);
		void SET_Y(test_b &, int); /*fonksiyon prototipi tan�mland� ��nk� burada de�il d��ar�da fonksiyon i�eri�i yaz�lmal�d�r.*/
		friend std::ostream& operator<<(std::ostream &, test_a &);
		friend std::istream& operator>>(std::istream &, test_a &);
};

class test_b
{
	private:
		int y;
	public:
		int GET_Y(){return y;}
		void SET_Y(int inpy){y = inpy;}
		friend class test_a; /*test_a s�n�f�n�n bu s�n�fa arkada� oldu�unu bu s�n�ftan �d�n� alabilece�ini belirttik.*/
};
/*Friends fonksiyonlar� g�rm��t�k bu sefer de s�n�flar i�erisinde arkada�l�k nas�l oluyor bakal�m. Bir s�n�f di�er s�n�f ile arkada�
ise di�er s�n�f�n metodlar� veya de�i�kenleri �zerinde de�i�iklik yapabilme yetisine sahip olur �rnek olarak burda yapal�m.*/

void SET_X(test_a &t, int inpx)
{t.x = inpx;} /*friend fonksiyon.*/

void test_a::SET_Y(test_b &t, int inpy)
{t.y = inpy;}

std::ostream& operator<<(std::ostream& o, test_a &t)
{o << t.x; return o;}

std::istream& operator>>(std::istream &i, test_a &t)
{i >> t.x; return i;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test_a t1; test_b t2;
	SET_X(t1, 15);
	std::cout << "x: " << t1.GET_X() << std::endl;
	t1.SET_Y(t2, 18);/*Friend s�n�f� i�erisinden set edildi.*/
	std::cout << "y: " << t2.GET_Y() << std::endl;
	t2.SET_Y(5); /*Kendi �zerinden set edildi.*/
	std::cout << "y: " << t2.GET_Y() << std::endl;
	std::cout << t1 << std::endl;
	std::cin >> t1;
	std::cout << t1 << std::endl;
	/*
	E�er referans & parametreye:
		pointer ise *isim ile
		normal ise sadece isim ile
	E�er pointer * parametreye
		pointer ise sadece isim ile
		normal ise &isim ile
		
		iki i�lem de referans olarak al�r ve �zerinde de�i�iklik yapabilmemize olanak sa�lar.
	*/
	return 0;
}
