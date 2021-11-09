#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Destructor Metodlar;
	Consturctor s�n�ftan nesne t�retildi�i anda yani ba�lang�� olarak �al��an ve �zellik veya metodlar�na eri�erek i�lem yapabilen
bir metoddur. Destructor ise bu s�n�ftan �retilen nesnenin �mr� son bulunca yani ramden silinmeden hemen �nce �al��an i�lemlerdir.
pointerlar i�in;
	delete komutu �al��t��� zaman �al���r.
de�i�kenler i�in;
	program bitirildi�i anda de�i�kenler de silinir bu s�randa �al���r.
	
	Genellikle nesne i�erisinde pointer bir de�i�ken kullanarak ve yer ay�rarak ba�lamam�z gerekiyor constructor ile bunu
sa�lad�ktan sonra ramin �i�mesini engellemek i�in yine delete yapmam�z gerekir. Bunu ise destructor metodunda sa�l�yoruz.
~s�n�fismi() -> �eklinde tan�mlan�r.
*/

class coordinate
{
	private:
		int *x;
		int *y;
	public:
		coordinate(int, int);
		~coordinate()
		{delete x; delete y; std::cout << "Destructor �al��t� ve bellek temizlendi. koordinat = (" << *x << ", " << *y << ")"
		<< std::endl;}
		void SET_COORDINATE(int, int);
		int GET_X(){return *x;}
		int GET_Y(){return *y;}
};

coordinate::coordinate(int x = 0, int y = 0)
{
	this->x = new int(); this->y = new int();
	*(this->x) = x; *(this->y) = y;
	std::cout << "Consturctor �al��t� ve bellekte yer ayr�ld�. koordinat = (" << *(this->x) << ", " << *(this->y) << ")"
	<< std::endl;
}

void coordinate::SET_COORDINATE(int x, int y)
{
	*(this->x) = x; *(this->y) = y; 
	std::cout << "(" << *(this->x) << ", " << *(this->y) << ") koordinatlar� ayarland� !" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	int inpx; int inpy;
	coordinate *c1 = new coordinate(5, 2);
	coordinate c2;
	std::cout << "Koordinat x: "; std::cin >> inpx;
	std::cout << "Koordinat y: "; std::cin >> inpy;
	c2.SET_COORDINATE(inpx, inpy);
	delete c1;	
	return 0;
}


