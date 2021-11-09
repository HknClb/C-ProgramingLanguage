#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Const de�i�ken;
	Program i�erisinde pi say�s� gibi nesneye �zel bir de�er vermemiz gerekebilir bu i�lemler i�in const kullan�l�r.
*/

class test
{
	private:
		int *x;
	public:
		const int y; /*const sadece okunabilir oldu�u i�in private yapmaya gerek yok.*/
		test(int, int);	
		~test()
		{delete x; std::cout << "Y�k�c� �al��t�.\n\tx = " << *x << " ve sabit y = " << y << std::endl;}
};

test::test(int x = 0, int y = 0): y(y)
{
	/*x ve y i�in de�erleri buradan yapamay�z ��nk� tan�mlama yap�ld��� anda de�erini de�i�tiremeyiz yani
	const int y k�sm�na  gelerek tan�mlama yap�lmadan �nce biz de�er atmam�z gerekiyor bunu ise kurucu fonksiyonun yan�na :
	karakteri ile yazarak fonksiyonmu� gibi de�er atayabiliri.*/
	this->x = new int(x);
	std::cout << "Kurucu �al��t�.\n\tx = " << *(this->x) << " ve sabit y = " << this->y << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test *t1 = new test();
	
	delete t1;
	return 0;
}

