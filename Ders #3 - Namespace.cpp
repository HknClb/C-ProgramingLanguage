#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Bu kodun anlam� standart isim uzay�n� kulland�r.*/
//using namespace std; using sabit t�m kaynak kodda kullan�lan isim uzay�n� belirler.

/*�sim uzaylar� �rne�in bir ortak projede �al���yorsunuz ve farkl� kaynak kodlar� �zerinde �al���yorsunuz �rne�in projemiz i�erisinde
for d�ng�s� kullan�r�z ve for d�ng�s� i�in al��ageldik olan i de�i�kenidir bu y�zden i yi her iki programc� da tan�mlar daha sonra program
birle�tirilip derlendi�i zaman iki adet ayn� isimli de�i�ken tan�mlamas� yap�ld��� i�in hata verir bu y�zden isim uzaylar� kullan�l�r.
�rne�in biz bir program yazal�m program�n amac� 5 boyutlu bir int dizisine kullan�c�dan ald��� de�erleri atan ve bu de�erleri sonras�nda
ekrana yazan bir program. Yazma k�sm�n� ayr� programc� atama i�lemini ayr� programc� yaps�n.*/

namespace programmerone
{
	int i;
	int dizi[5];
	void SET_VALUE(int *a)
	{
		std::cout << "Girmek istedi�iniz de�er: "; std::cin >> *a;
	}
}

namespace programmertwo
{
	int i;
	int GET_VALUE(int *a)
	{
		return *a;
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	for(programmerone::i = 0; programmerone::i < 5; programmerone::i++)
		programmerone::SET_VALUE(&programmerone::dizi[programmerone::i]);
	for(programmertwo::i = 0; programmertwo::i < 5; programmertwo::i++)
		std::cout << programmertwo::GET_VALUE(&programmerone::dizi[programmertwo::i]) << std::endl;
	return 0;
}



