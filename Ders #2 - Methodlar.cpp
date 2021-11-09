#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

class coordinate
{
	private:
		int x;
		int y;
	public:
		/*S�n�f i�erisindeki de�i�kenler bir nesnenin �zellikleri olurken, davran��lar� ise methodlar� yani fonksiyonlar� olur. Her 
		tan�mlamada oldu�u gibi methodlar�n da eri�im belirte�leri ile ba�lant�s� vard�r. E�er public olmaz ise nesne �zerinden direkt
		olarak methoda eri�ilemez. Buradaki �rnekte private olarak iki adet �zellik x ve y de�i�kenlerini tan�mlad�k fakat biz nesne
		�zerinden bu x ve y de�i�kenine eri�emeyiz bu y�zden set ve get metodlar� olu�turup bunlar� kullan�yoruz. Bir s�n�f i�erisinde
		metod olu�turabilir veya prototipini olu�turup d��ar�da i�eri�ini belirtebilirsin. Bunun sebebi �rne�in genel bir s�n�f var 
		ba�ka bir yerden ald���m�z s�n�f modelini kullan�yoruz, bu s�n�f modelindeki metodlar� tekrar de�i�tirmek isteyebiliriz bunun
		sebebi budur.*/
		/*��eride olu�turulmu� metodlar.*/
		void SET_X(int inpx)
		{x = inpx;}
		int GET_X()
		{return x;}
		
		/*Prototipi olu�turulmu� metod.*/
		void SET_Y(int inpy);/*sadece int yazmam�z yeterli olur.*/
		int GET_Y();
};

/*S�n�f i�erisindeki bir yap�ya ola�abilmek i�in :: kullan�l�r.*/
int coordinate::GET_Y(){return this->y;}
void coordinate::SET_Y(int inpy){this->y = inpy;}
/*This kodu bizim nesnemiz �zerinden bu metod �a�r�ld��� zaman nesne i�in anlam�na gelen bu nesnenin x �zelli�i anlam�na gelir.*/

int main()
{
	setlocale(LC_ALL, "Turkish");
	coordinate c1;
	int inpx; int inpy;
	std::cout << "X: "; std::cin >> inpx;
	std::cout << "Y: "; std::cin >> inpy;
	c1.SET_X(inpx); c1.SET_Y(inpy);
	std::cout << "Koordinatlar: (" << c1.GET_X() << ", " << c1.GET_Y() << ")" << std::endl;
	return 0;
}
