#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

class base
{
	public:
		void print()
		{std::cout << "Base Class Is Printed !" << std::endl;}
		void show()
		{std::cout << "Base Class Is Shown !" << std::endl;}	
};

class derived : public base
{
	public:
		void print()
		{std::cout << "Derived Class Is Printed !" << std::endl;}
		void show()
		{std::cout << "Derived Class Is Shown !" << std::endl;}	
};

class vbase
{
	public:
		vbase()
		{print();}
		void virtual print()
		{std::cout << "VBase Class Is Printed !" << std::endl;}
		void show()
		{std::cout << "VBase Class Is Shown !" << std::endl;}	
};

class vderived : public vbase
{
	public:
		void print()
		{std::cout << "VDerived Class Is Printed !" << std::endl;}
		void show()
		{std::cout << "VDerived Class Is Shown !" << std::endl;}	
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	/*Not:
		�ki adet farkl� t�retilmi� s�n�f� ayn� anda bir dizi i�erisinde tutmam�z gerekebilir bunu gelecek derste g�rece�iz. 
	*/
	derived d;
	base *bptr = &d;
	/*
		bptr pointer� bir base s�n�f� tutabilecek kadar yer ayr�lm�� ve adres tutan de�i�kendir ve d nesnesi ise bir base s�n�f� ve bir
	derived s�n�f� tutabilecek boyuttad�r ram de ki �ekli ise 
	->bptr[CLASS BASE]
			   [CLASS BASE]
	->Object d 
			   [CLASS DERIVED]
		Bir de�i�kenin adresi e�er dizi ise bile ba�lang�� adresini g�sterir bu y�zden biz yukardaki bptr = &d; yapt���m�z zaman bptr
	pointer� d nesnesinin base s�n�f�n� tutar.	
	*/
	bptr->print();
	bptr->show(); 
	std::cout << std::endl;
	vderived vd;
	vbase *vbptr = &vd;
	vbptr->print();
	vbptr->show();
	return 0;
}












