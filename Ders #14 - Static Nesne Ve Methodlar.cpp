#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include "test.h"
int test::derivative = 0;
int test::deleted = 0;
/*
Sabit �zellik ve De�i�ken: 
	Sabit olarak bir de�i�ken tan�mland��� zaman tan�mland��� anda de�er g�zetmeksizin sabitlenir ram e yani program kapanana kadar ram de
sabit olarak kal�r ve ba�ka tan�mlamalar yap�lsa dahi umrunda olmaz.
Sabit Fonksiyon ve Metod:
	Sabit olarak tan�mlanan bir fonksiyon s�n�f i�erisinde ise ve public durumda ise illa bir nesne �retip o nesne �zerinden eri�memize
gerek yok yani s�n�f ismi test olsun test i�erisinde de static a fonksiyonu var biz a fonksiyonunu �al��t�rmak i�in test.a �eklinde 
yazabiliriz.
*/

int main()
{
	setlocale(LC_ALL, "Turkish");
	test t1(3, 5, 7, 8);
	test *t2 = new test;
	test *t3 = new test(t1);
	t1.Write_Info();
	delete t2;
	t1.Write_Info();
	delete t3;
	t1.Write_Info();
	return 0;
}




