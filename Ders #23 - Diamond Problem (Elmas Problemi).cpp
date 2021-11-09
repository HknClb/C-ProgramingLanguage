#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*
Diamond Problem:
	A isminde bir taban s�n�f�ndan miras alan B ve C s�n�flar� var olsun ve B ve C s�n�flar�ndan miras alan D s�n�f� var oldu�unu d���nelim.
class D : public B, public C
{

};
�eklinde ise D s�n�f�ndan bir nesne �retildi�i zaman ilk olarak B den kal�t�m al�nd��� i�in B s�n�f�, B s�n�f� da A s�n�f�ndan kal�t�m
ald��� i�in A s�n�f� �retilir �zellik ve metodlar� tan�mlan�r daha sonra B, sonra ise C s�n�f�na ge�er ve C s�n�f� da A s�n�f�ndan miras
ald��� i�in A s�n�f� �retilir �zellik ve metodlar� tan�mlan�r daha sonra C s��n�f� tan�mlan�r sonra ise D s�n�f� tan�mlan�r yani ram de
G�r�nt� �u �ekildedir.
Variable			Value			Type
 >D					{...}			  D
   >B				{...}			  B
     >A				{...}			  A
   >C				{...}			  C
   	 >A				{...}			  A
   	Yani ram de iki adet A s�n�f� tan�mlanm�� oldu biri B i�in di�eri ise C i�in Bunun �n�ne ge�memiz gerekiyor bunun i�in ise virtual
class yani sanal s�n�f kullanmam�z gerekiyor.
*/

class A
{
	protected:
		int val;
		static int derivedval; /*A s�n�f�ndan �retilme say�s�n� tutan de�i�ken.*/
	public:
		A(int);
		~A()
		{std::cout << "A's Destructor Worked !" << std::endl;}
		void SET_VAL(int);
		int GET_VAL(){return val;}	
};
int A::derivedval = 0;

A::A(int val = 1) : val(val)
{
	this->derivedval++;
	std::cout << "A's Constructor Worked !" << std::endl << "Val's Value: " << this->val << std::endl << "A Class " << this->derivedval 
	<< " More Derived !" << std::endl;
}

void A::SET_VAL(int val)
{this->val = val;}

class B : virtual public A /*T�retilen s�n�f e�er bir kez t�retildi ise sanal olarak yani ger�ek olarak t�retme anlam�na gelir.*/
{
	public:
		B(int);
		~B()
		{std::cout << "B's Destructor Worked !" << std::endl;}	
};

B::B(int val = 1) : A(val)
{std::cout << "B's Constructor Worked !" << std::endl << "Val's Value: " << this->val << std::endl;}

class C : virtual public A
{
	public:
		C(int);
		~C()
		{std::cout << "C's Destructor Worked !" << std::endl;}	
};

C::C(int val = 1) : A(val)
{std::cout << "C's Constructor Worked !" << std::endl << "Val's Value: " << this->val << std::endl;}

/*
	B ve C s�n�flar�n�n ikisi i�in de virtual yapt�k ��nk� D s�n�f� ilk kal�t�m� hangi s�n�f dan alaca��n� bilemeyiz. �lk olarak bu
durumda B s�n�f� kal�t�m al�n�r ve ordan A s�n�f� �retilir bak�l�r e�er �retilmemi� ise direkt �retilir sonra ise B s�n�f� �retilir.
C s�n�f�na ge�ilir ve A s�n�f� �retilir bak�l�r �retilmi� bu y�zden sanal olarak �retilir.
*/

class D : public B, public C
{
	public:
		D(int);	
		~D()
		{std::cout << "D's Destructor Worked !" << std::endl;}
};

D::D(int val = 1) : D::A(val) /*Burada hangi s�n�f i�in oldu�unu belirmemiz gerekir.  	*/
{std::cout << "D's Constructor Worked !" << std::endl << "Val's Value: " << this->val << std::endl;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	std::cout << "Derived A Class" << std::endl;
	A a(3);
	std::cout << std::endl << "Derived B Class" << std::endl;
	B b(5);
	std::cout << std::endl << "Derived C Class" << std::endl;
	C c(7);
	std::cout << std::endl << "Derived D Class" << std::endl;
	D d(10);
	return 0;
}


















