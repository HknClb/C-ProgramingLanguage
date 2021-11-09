#include <iostream>
#include <string>
#include <locale>

/*Constructor kurucu anlam�na gelir bir s�n�ftan nesne t�retildi�i anda otomatik olarak �al��an metoddur varsay�lan olarak s�n�f i�erisine
bir kurucu tan�mlamas� yapmaz isek default olarak g�vdesi bo� olarak bir kurucu tan�mlan�r. Kurucu fonksiyonlarda dikkat edilmesi gerekenler

-Kurucu fonksiyonlar public eri�im belirteci alt�na yaz�lmak zorundad�r.
-Kurucu fonksiyonlar s�n�f�n ismi ile ayn� olmak zorundad�r.
-Kurucu fonksiyonlar geriye bir tip d�ndermez.
-Bir kurucu fonksiyon var ise ve 2 adet parametre al�yor ise o s�n�ftan parametresiz bir nesne t�retemeyiz veya parametresiz bir kurucu
fonksiyon olu�turmak zorunday�z.*/

class test
{
	private:
		int x;
		int y;
	public:
		test(); /*Paramatresiz kurucu*/
		test(int, int); /*�ki parametreli kurucu*/
		int GET_X(){return x;}
		int GET_Y(){return y;}
		/*Prototip olarak tan�mlamayabiliriz i�eride direkt olarak i�lem yapabiliriz.*/
};

test::test()
{
	std::cout << "Parametresiz Constructor �al��t� !" << std::endl;
	x = y = 5;
}

test::test(int x, int y = 5)
{
	std::cout << "Parametreli Constructor �al��t� !" << std::endl;
	this->x = x;
	this->y = y;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test t1;
	return 0;
}




