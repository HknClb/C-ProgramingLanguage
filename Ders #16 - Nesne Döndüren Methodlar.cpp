#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*
	�ki adet nesneyi toplamak isteyebiliriz fakat bu nesnenin hangi �zelliklerini topluyaca��n� program bilemez bu y�zden bir metod yazmak
zorunday�z ve bu metod dan sonra ise toplam nesneyi d�nd�rmemiz gerekir.
*/

class coordinate
{
	private:
		int x;
		int y;
	public:
		coordinate(int, int);
		void SET_COORDINATE(int, int);
		int GET_X(){return x;}
		int GET_Y(){return y;}
		const coordinate GET_COLLECTION(const coordinate &);
};

coordinate::coordinate(int x = 0, int y = 0) : x(x), y(y){}

void coordinate::SET_COORDINATE(int x = 0, int y = 0)
{this->x = x; this->y = y;}

const coordinate coordinate::GET_COLLECTION(const coordinate &c)
{coordinate total; int x = this->x + c.x; int y = this->y + c.y; total.SET_COORDINATE(x, y); return total;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	coordinate c1(3, 5);
	coordinate c2(4, 8);
	coordinate total = c1.GET_COLLECTION(c2);
	std::cout << "Toplam x: " << total.GET_X() << "\nToplam y: " << total.GET_Y() << std::endl;
	return 0;
}
