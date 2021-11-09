#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Inheritance:
	Kal�t�m �rne�in bir insan s�n�f� var ve biz bir otomasyon sistemi yap�yoruz bu otomasyon sisteminde bizde m��teri ve personel olmas�
gerekir ve personel i�erisinde y�ksek y�netici, y�netici, ve i��i s�n�f� olmas� gerekir bunun gibi sistemler i�in kal�t�m kullan�l�r.
*/

typedef enum s
{
	male = 0,
	famale = 1,
	null = 2	
}sex;

typedef enum r
{
	turk = 0,
	british = 1,
	italy = 2,
	french = 3,
	nulls = 4
}race;

typedef enum e
{
	middleschool = 0,
	highschool = 1,
	university = 2,
	nullss = 3
}education;

class human
{
	protected:
		std::string passportno;
		std::string name;
		int age;
		sex gender;	
		race nationality;
	public:
		human(std::string, std::string, int, sex, race);
		void SET_PASSPORTNO(std::string);
		void SET_NAME(std::string);
		void SET_AGE(int);
		void SET_GENDER(sex);
		void SET_NATIONALITY(race);
		std::string GET_PASSPORTNO(){passportno.empty() ? passportno = "NULL" : passportno ; return passportno;}
		std::string GET_NAME(){name.empty() ? name = "NULL" : name; return name;}
		int GET_AGE(){age == 0 ? age = -987789 : age; return age;}
		std::string GET_GENDER()
		{
			switch(gender)
			{
				case 0:
					return "Erkek";
					break;
				case 1:
					return "Kad�n";
					break;
				default:
					return "NULL";
					break;
			}
		}
		std::string GET_NATIONALITY()
		{
			switch(nationality)
			{
				case 0:
					return "T�rk";
					break;
				case 1:
					return "�ngiliz";
					break;
				case 2:
					return "�talyan";
					break;
				case 3:
					return "Frans�z";
					break;
				default:
					return "NULL";
					break;
			}
		}
};

human::human(std::string passportno = "", std::string name = "", int age = 0, sex gender = null, race nationality = nulls)
{this->passportno = passportno; this->name = name; this->age = age; this->gender = gender; this->nationality = nationality;}

void human::SET_PASSPORTNO(std::string passportno)
{this->passportno = passportno;}

void human::SET_NAME(std::string name)
{this->name = name;}

void human::SET_AGE(int age)
{this->age = age;}

void human::SET_GENDER(sex gender)
{this->gender = gender;}

void human::SET_NATIONALITY(race nationality)
{this->nationality = nationality;}

/*: public anas�n�fismi yapt���m�z zaman burdaki public eri�im belirteci s�n�f�n nas�l miras alaca��na dayan�r yani biz student class
�ndan bir nesne t�retti�imiz zaman human �zelliklerine nas�l eri�ece�imizi belirtir.*/
class student : public human
{
	private:
		std::string studentnumber;
		education educationstatus;
		short int grade;
	public:
		student(std::string, education, short int, std::string, std::string, int, sex, race);
		void SET_STUDENTNUMBER(std::string);
		void SET_EDUCATIONSTATUS(education);
		void SET_GRADE(short int);
		std::string GET_STUDENTNUMBER(){return studentnumber;}
		std::string GET_EDUCATIONSTATUS()
		{
			switch(educationstatus)
			{
				case 0:
					return "Ortaokul";
					break;
				case 1:
					return "Lise";
					break;
				case 2:
					return "�niversite";
					break;
			}
		}
		short int GET_GRADE(){return grade;}
};

/*
Constructor Methodunun Kal�t�mda Davran���
	�lk olarak temel s�n�f�n constructoru �al���r ve daha sonra miras alan yani di�er t�retilmi� s�n�flar�n constructoru �al���r.
Burada ise student s�n�f� human s�n�f�ndan miras al�yor ve human temel student t�retilmi� s�n�ft�r yani ba�lang�� olarak human s�n�f�n�n
constructoru �al��acakt�r yani biz e�er t�retilmi� s�n�ftan bir nesne t�retirsek temel s�n�f�n construcoru na default olarak parametre
verilmez ise �u de�erleri al gibi = de�er yazar isek veya parametresiz bir constructor yazar isek kodumuz s�k�nt�s�z �al���r fakat
ba�lang�� olarak nesne t�retilirken parametre veremeyiz. Bunu engellemenin yolu ise student s�n�f�n�n kurucusuna ba�lang�� olarak bir
parametreli constructor �a��rmak olacakt�r yani nesne t�retildi�i an itibari ile nesneye de�er atabilece�iz. Hat�rlarsak const bir
de�i�ken tan�mlarken : �eklinde atama yap�yorduk yani t�retilmi� s�n�f�n nesnesi t�retilmeden �nce �zellikleri ve metodlar� belirtilmeden
�nce tan�mlama an�nda direkt olarak const a de�er atarak read-only den �nce bir de�er atabilmeyi ba�ar�yorduk. Bu da bu �ekildedir.

Destructor Methodunun Kal�t�mda Davran���
	�lk olarak t�retilmi� s�n�f sonlan�r daha sonra ise temel s�n�f sonlan�r.
*/
student::student(std::string studentnumber = "", education educationstatus = nullss, short int grade = 1, 
std::string passportno = "", std::string name = "", int age = 0, sex gender = null, race nationality = nulls) : human(passportno, name, 
age, gender, nationality)
{this->studentnumber = studentnumber; this->educationstatus = educationstatus; this->grade = grade;}

void student::SET_STUDENTNUMBER(std::string studentnumber)
{this->studentnumber = studentnumber;}

void student::SET_EDUCATIONSTATUS(education educationstatus)
{this->educationstatus = educationstatus;}

void student::SET_GRADE(short int grade)
{this->grade = grade;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	student m1("181312025", university, 2, "14501321120", "Hakan �ELEB�", 20, male, turk);
	/*m1.SET_AGE(20);
	m1.SET_GENDER(male);
	m1.SET_NAME("Hakan �ELEB�");
	m1.SET_NATIONALITY(turk);
	m1.SET_PASSPORTNO("14501321120");*/
	std::cout << "�sim: " << m1.GET_NAME() << "\nYa�: " << m1.GET_AGE() << "\nCinsiyet: " << m1.GET_GENDER() << "\nMilliyet: "
	<< m1.GET_NATIONALITY() << "\nPasaport Numaras�: " << m1.GET_PASSPORTNO() << "\nE�itim Durumu: " << m1.GET_EDUCATIONSTATUS()
	<< "\n��renci No: " << m1.GET_STUDENTNUMBER() << "\nS�n�f: " << m1.GET_GRADE() << std::endl;
	return 0;
}
