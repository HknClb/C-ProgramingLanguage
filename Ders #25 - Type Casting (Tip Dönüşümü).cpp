#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include "mytime.h"
/*
	string GET_NOW_DATE() -> G�N-AY-YIL B���M�NDE TAR�H VER�R
	int GET_NOW_DAY(STR�NG G�N-AY-YIL) -> int olarak g�n� verir.
	int GET_NOW_MONTH(STR�NG G�N-AY-YIL) -> int olarak ay� verir.
	int GET_NOW_YEAR(STR�NG G�N-AY-YIL) -> int olarak y�l� verir.
	bool Is_Right_Format(string date) -> Format do�ru ise true yanl�� ise false
*/

class human
{
	protected:
		std::string fullname;
		std::string passportno;
		std::string birthdate;
		int age;
	public:
		human(std::string, std::string, std::string);
		void SET_FULLNAME(std::string);
		void SET_PASSPORTNO(std::string);
		void SET_BIRTHDATE(std::string);
		std::string GET_FULLNAME()
		{return fullname;}
		std::string GET_PASSPORTNO()
		{return passportno;}
		std::string GET_BIRTHDATE()
		{return birthdate;}
		void GET_INFOAGE()
		{
			if(Is_Right_Format(birthdate))
			{
				int bday = GET_NOW_DAY(birthdate);
				int bmonth = GET_NOW_MONTH(birthdate);
				int byear = GET_NOW_YEAR(birthdate);
				std::string ndate = GET_NOW_DATE();
				int nday = GET_NOW_DAY(ndate);
				int nmonth = GET_NOW_MONTH(ndate);
				int nyear = GET_NOW_YEAR(ndate);
				if(bmonth > nmonth)
				{
					if(bday > nday)
					{
						std::cout << age << " Ya�� doldurulmu�" << std::endl << age + 1 << " Ya��n� doldurmaya " << bmonth - nmonth
						<< " Ay - " << bday - nday << " G�n vard�r." << std::endl;
					}
					else if(bday == nday)
					{
						std::cout << age << " Ya�� doldurulmu�" << std::endl << age + 1 << " Ya��n� doldurmaya " << bmonth - nmonth
						<< " Ay vard�r." << std::endl;
					}
					else
					{
						std::cout << age << " Ya�� doldurulmu�" << std::endl << age + 1 << " Ya��n� doldurmaya " << (bmonth - nmonth) - 1
						<< " Ay - " << 31 - (nday - bday) << " G�n vard�r." << std::endl;
					}
				}
				else if(bmonth == nmonth)
				{
					if(bday > nday)
					{
						std::cout << age << " Ya�� doldurulmu�" << std::endl << age + 1 << " Ya��n� doldurmaya " << bday - nday << " G�n vard�r." 
						<< std::endl;
					}
					else if(bday == nday)
					{
						std::cout << age << " Ya�� bug�n doldurulmu� ve do�um g�n�" << std::endl;
					}
					else
					{
						std::cout << age << " Ya�� doldurulmu� " << std::endl << age + 1 << " Ya��n� doldurmaya " << 11 << " Ay - "  
						<< 31 - (nday - bday) << " G�n vard�r." << std::endl;
					}
				}
				else
				{
					if(bday > nday)
					{
						std::cout << age << " Ya�� doldurulmu� " << std::endl << age + 1 << " Ya��n� doldurmaya " << 12 - (nmonth - bmonth) 
						<< " Ay - " << bday - nday << " G�n vard�r." << std::endl;
					}
					else if(bday == nday)
					{
						std::cout << age << " Ya�� doldurulmu� " << std::endl << age + 1 << " Ya��n� doldurmaya " << 12 - (nmonth - bmonth) 
						<< " Ay vard�r " << std::endl;
					}
					else
					{
						std::cout << age << " Ya�� doldurulmu� " << std::endl << age + 1 << " Ya��n� doldurmaya " << 12 - (nmonth - bmonth) 
						<< " Ay - "	<< 31 - (nday - bday) << " G�n vard�r." << std::endl;
					}
				}
			}
			else
				std::cout << "Do�um g�n� format� yaln�� !" << std::endl;
		}
		int GET_AGE()
		{
			if(Is_Right_Format(birthdate))
			{
				int bday = GET_NOW_DAY(birthdate);
				int bmonth = GET_NOW_MONTH(birthdate);
				int byear = GET_NOW_YEAR(birthdate);
				std::string ndate = GET_NOW_DATE();
				int nday = GET_NOW_DAY(ndate);
				int nmonth = GET_NOW_MONTH(ndate);
				int nyear = GET_NOW_YEAR(ndate);
				if(bmonth > nmonth)
				{
					if(bday > nday)
						age = (nyear - byear) - 1;
					else if(bday == nday)
						age = (nyear - byear) - 1;
					else
						age = (nyear - byear) - 1;
				}
				else if(bmonth == nmonth)
				{
					if(bday > nday)
						age = (nyear - byear) - 1;
					else if(bday == nday)
						age = nyear - byear;
					else
						age = nyear - byear;
				}
				else
				{
					if(bday > nday)
						age = nyear - byear;
					else if(bday == nday)
						age = nyear - byear;
					else
						age = nyear - byear;
				}
			}
			else
				std::cout << "Do�um g�n� format� yaln�� !" << std::endl;
			return age;
		}	
};

human::human(std::string fullname, std::string passportno, std::string birthdate)
{
	if(passportno.length() == 11 && (passportno[10] - '0') % 2 == 0 && Is_Right_Format(birthdate) == true)
	{
		this->fullname = fullname; this->passportno = passportno; this->birthdate = birthdate;
	}
	else
	{
		std::cout << "Nesne yaln�� olu�turuldu T.C.K.N. veya do�um g�n� tarih format� yaln�� !" << std::endl << "Nesne siliniyor..."
		<< std::endl;
		delete this;	
	}
}

void human::SET_FULLNAME(std::string fullname)
{this->fullname = fullname;}

void human::SET_PASSPORTNO(std::string passportno)
{
	if(passportno.length() == 11 && (passportno[10] - '0') % 2 == 0)
		this->passportno = passportno;
	else
		std::cout << "T.C.K.N. yanl�� girilmi� !" << std::endl;
}

void human::SET_BIRTHDATE(std::string birthdate)
{
	if(Is_Right_Format(birthdate))
		this->birthdate = birthdate;
	else
		std::cout << "Do�um g�n� yaln�� veya yaln�� formatta girilmi� !" << std::endl;
}

class footballer : public human
{
	private:
		std::string team;
	public:
		footballer(std::string, std::string, std::string, std::string);
		void SET_TEAM(std::string);
		std::string GET_TEAM()
		{return team;}	
};

footballer::footballer(std::string fullname, std::string passportno, std::string birthdate, std::string team) : human(fullname, passportno, birthdate)
{this->team = team;}

class engineer : public human
{
	private:
		std::string programinglanguage;
	public:
		engineer(std::string, std::string, std::string, std::string);
		void SET_PROGRAMMINGLANGUAGE(std::string);
		std::string GET_PROGRAMINGLANGUAGE()
		{return programinglanguage;}	
};

engineer::engineer(std::string fullname, std::string passportno, std::string birthdate, std::string programinglanguage) : human(fullname, passportno,
birthdate)
{this->programinglanguage = programinglanguage;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	human person1("Halil Emre Balaban", "15544844810", "04-06-2001");
	std::cout << "�sim Soyisim: " << person1.GET_FULLNAME() << std::endl << "T.C.K.N.: " << person1.GET_PASSPORTNO() << std::endl << "Ya�: "
	<< person1.GET_AGE() << std::endl << "Do�um Tarihi: " << person1.GET_BIRTHDATE() << std::endl << std::endl;
	footballer socer1("Abdullah ALTUNKAYNAK", "18971448530", "14-06-1999", "Fenerbah�e");
	std::cout << "�sim Soyisim: " << socer1.GET_FULLNAME() << std::endl << "T.C.K.N.: " << socer1.GET_PASSPORTNO() << std::endl << "Ya�: "
	<< socer1.GET_AGE() << std::endl << "Do�um Tarihi: " << socer1.GET_BIRTHDATE() << std::endl << "Tak�m: " << socer1.GET_TEAM() << std::endl
	<< std::endl;
	engineer pen("Hakan �ELEB�", "14501321120", "26-08-2000", "C#");
	std::cout << "�sim Soyisim: " << pen.GET_FULLNAME() << std::endl << "T.C.K.N.: " << pen.GET_PASSPORTNO() << std::endl << "Ya�: "
	<< pen.GET_AGE() << std::endl << "Do�um Tarihi: " << pen.GET_BIRTHDATE() << std::endl << "Programlama Dili: " << pen.GET_PROGRAMINGLANGUAGE()
	<< std::endl << std::endl << std::endl;
	/*Bu k�s�m up type casting*/
	human *ary[3];
	ary[0] = &person1;
	ary[1] = &socer1;
	ary[2] = &pen;
	for(int i = 0; i < 3; i++)
		std::cout << ary[i]->GET_FULLNAME() << std::endl;
	std::cout << std::endl << std::endl;
	std::string searchingname;
	std::cout << "Aratmak istedi�iniz isim: "; getline(std::cin, searchingname);
	searchingname = "Hakan �ELEB�";
	for(int i = 0; i < 3; i++)
	{
		if(ary[i]->GET_FULLNAME() == searchingname)
		{
			std::cout << "�sim Soyisim: " << ary[i]->GET_FULLNAME() << std::endl << "T.C.K.N.: " << ary[i]->GET_PASSPORTNO() << std::endl << "Ya�: "
			<< ary[i]->GET_AGE() << std::endl << "Do�um Tarihi: " << ary[i]->GET_BIRTHDATE() << std::endl;
			ary[i]->GET_INFOAGE();
			std::cout << std::endl << std::endl;
		}
		else
			std::cout << "Bu isim " << i + 1 << ".s�rada de�il !" << std::endl;
	}
	/*Bu k�s�p down type casting*/
	engineer *pe = (engineer *)ary[2];
	std::cout << "�sim Soyisim: " << pe->GET_FULLNAME() << std::endl << "T.C.K.N.: " << pe->GET_PASSPORTNO() << std::endl << "Ya�: "
	<< pe->GET_AGE() << std::endl << "Do�um Tarihi: " << pe->GET_BIRTHDATE() << std::endl << "Programlama Dili: " << pe->GET_PROGRAMINGLANGUAGE()
	<< std::endl << std::endl << std::endl;
	return 0;
}
