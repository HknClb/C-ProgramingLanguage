/*�rnek: Bir veya daha fazla oyunculu d��manlar�n var oldu�u bir oyun.*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
/*Written by Hakan �ELEB�*/

/*�nsan, k�pek, kedi gibi hayvan yada insanlar vard�r bunlar�n ortak �zelli�i canl�l�kt�r yanli canli s�n�f�*/
class canli
{
	/*Sadece s�n�f i�erisinden eri�ilebilen tan�mlamalar.*/
	private:
		int age;
	/*Her yerden yani olu�turulan nesne veya kal�t�m yap�lan s�n�f tan eri�ilebilen tan�mlamalar.*/
	public:
		std::string fullname;
		/*D��ardan age de�i�kenine eri�ilemedi�i i�in set metodu ile ya� ayarlan�yor.*/
		bool SET_AGE(int inpage)
		{
			age = inpage;
			return (age > -1);
		}
		/*D��ardan age de�i�kenine eri�ilemedi�i i�in get metodu ile ya� de�i�kenin de�erine eri�ilebiliyor.*/
		int GET_AGE()
		{return age;}
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	/*Pointer ile canli s�n�f�ndan t�retilen insan nesnesi olu�turuldu*/
	canli *insan = new canli();
	int inpage;
	/*Kullan�c�dan ismi al�n�p insan nesnesinin ismine atan�yor.*/
	std::cout << "�simi: "; getline(std::cin, insan->fullname);
	/*Ya� 0'dan k���k olamaz set metodu i�erisinde bu kontrol ediliyor ve e�er ya� 0'dan k���k ise geriye 0 de�il ise geriye
	1 d�nderiyor geriye d�nderilen de�er 0 ise while tekrarlan�yor b�ylelikle ya��n 0'dan k���k girilmesi engelleniyor.*/
	do
	{
		std::cout << "Ya��: "; std::cin >> inpage;
	}while(!insan->SET_AGE(inpage));
	system("CLS");
	/*Get metodu ise geriye int bir de�er yani age d�nderiyor bu �ekilde age de�i�kenine eri�ilebiliyor.*/
	std::cout << "�simi: " << insan->fullname << "\nYa��: " << insan->GET_AGE() << std::endl;
	delete insan;
	return 0;
}
