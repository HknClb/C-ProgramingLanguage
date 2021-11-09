#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*
	Call By Referance fonksiyonlar�n� g�rm��t�k tan�mlanmas� �rne�in bir int x de�i�keninin de�erinin de�i�tirilmesi gerekiyor.
1.Yol
void referancesetvalue(int *x)
{
	std::cout << "De�i�tirilicek de�er: "; std::cin >> *x;
}
Bu �ekilde bir fonksiyon ile return gibi di�er i�lemler kullan�lmadan direkt olarak de�i�kenin de�eri de�i�tirilebilir.
fakat fonksiyon �a�r�l�rken:
referancesetvalue(&x); �eklinde �a��rmam�z gerekiyor. Bu �a��r�m bize
pointerlar bir kendi adresleri birde g�sterdi�i adresleri vard�r.
*ptr -> g�sterdi�i adresteki de�er.
ptr -> g�sterdi�i adres.
&ptr ->kendi adresi.
de�i�kenler ise de�er ve kendi adreslerini tutar.
x -> de�eri
&x -> kendi adresi
yani bu �a��r�mda *x = &x; �eklinde atama yapm�� olduk. x pointer�n�n g�sterdi�i adres x de�i�keninin adresi oldu. Bu sayede
x pointer � �zerinde de�i�iklik yapar isek x de�i�keni de de�i�mi� olur.
farkl� bir bi�imde Call By Referance yapmak istersek;

2.Yol
void referancesetvalue(int &x)
{
	std::cout << "De�i�tirilecek de�er: "; std::cin << x;
}
Burada ise fonksiyondaki x de�i�keninin adresine parametredeki x de�erinin adresini atmam�z gerekir yani �a�r�l�rken:
referancesetvalue(&x) �eklinde olmak zorundad�r.
*/

void firstway(int *x)
{
	int a = *x;
	std::cout << "De�i�tirilecek de�er: "; std::cin >> *x;
	std::cout << "x de�i�keni " << a << " de�erinden " << *x << " de�eri ile de�i�tirildi" << std::endl;
}

void secondway(int &x)
{
	int a = x;
	std::cout << "De�i�tirilecek de�er: "; std::cin >> x;
	std::cout << "x de�i�keni " << a << " de�erinden " << x << " de�eri ile de�i�tirildi" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	int x; int selection;
	std::cout << "Ba�lang�� de�eri: "; std::cin >> x;
	do
	{
		std::cout << "�lk yol[1]\n�kinci yol[2]\nYaz[3]\n��k��[4]\nSe�im: "; std::cin >> selection;
		switch(selection)
		{
			case 1:
				firstway(&x);
				break;
			case 2:
				secondway(x);
				break;
			case 3:
				std::cout << "x de�eri: " << x << std::endl;
				break;
			case 4:
				std::cout << "��k�� ger�ekle�ti." << std::endl;
				break;
			default:
				std::cout << "Ge�erli bir se�im yap�n�z !\n" << std::endl;
				break;
		}
	}while(selection != 4);
	return 0;
}




