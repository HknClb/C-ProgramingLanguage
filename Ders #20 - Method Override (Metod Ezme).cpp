#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <locale>

/*
Override:
	Ezme anlam�na gelir taban s�n�ftan t�retilmi� yani miras alm�� bir s�n�f var ise ve bu taban s�n�f�n bir metodu var fakata t�retilmi�
s�n�f i�in bu metod de�i�tirilmesi gerekiyor ise bu i�lemi yapmaya ezme override denir.
*/

class dot
{
	protected:
		double x;
		double y;
	public:
		dot(double, double);
		dot(dot &);
		void SET_COORDINATE(double, double);
		double GET_X(){return x;}
		double GET_Y(){return y;}
		double GET_PERIMETER(){return 0;}
		double GET_AREA(){return 0;}
			
};

dot::dot(double x = 0, double y = 0) : x(x), y(y){}

dot::dot(dot &d) : x(d.x), y(d.y){}

void dot::SET_COORDINATE(double x = 0, double y = 0)
{this->x = x; this->y = y;}

/*T�m geometrik �ekiller �izgiden �izgi ise noktadan var olur*/
class line : dot
{
	protected:
		dot *start;
		dot *end;
	public:
		line(dot, dot);
		~line(){delete start; delete end;}
		void SET_STARTEND(dot *, dot *);
		dot GET_START(){return *start;}
		dot GET_END(){return *end;}
		double GET_PERIMETER(){return sqrt((pow((start->GET_X() - end->GET_X()), 2) + pow(start->GET_Y() - end->GET_Y(), 2)));}
		/*OVERRIDE*/
		double GET_AREA(){return 1;}
};

line::line(dot start, dot end)
{this->start = new dot(start); this->end = new dot(end);}

void line::SET_STARTEND(dot *start, dot *end)
{this->start = start; this->end = end;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	dot *start = new dot(5, 2);
	dot *end = new dot(8, 6);
	line *newline = new line(*start, *end);
	delete start; delete end;
	std::cout << "Ba�lang��-x: " << newline->GET_START().GET_X() << std::endl << "Ba�lang��-y: " << newline->GET_START().GET_Y()
	<< std::endl << "Biti�-x: " << newline->GET_END().GET_X() << std::endl << "Biti�-y: " << newline->GET_END().GET_Y()
	<< std::endl << "Alan�: " << newline->GET_AREA() << std::endl << "�evresi: " << newline->GET_PERIMETER() << std::endl;
	delete newline;
	return 0;
}
