#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Biz bir say�y� +1 artt�ran bir fonksiyon yazd���m�z� farz edelim ve hem double hem int i�in �zel olarak bunu
yazmam�z gerekir bunun yerine derleyici otomatik alg�las�n diye tamplate vard�r.*/

template <typename T>
T Increase(T &val)
{
	val++;
}
/*Bunu class i�in yapal�m.*/

template <class T>
class test
{
	private:
		T data;
	public:
		test(T inpdata) : data(inpdata)
		{}
		void SET_DATA(T inpdata)
		{data = inpdata;}
		T GET_DATA()
		{return data;}	
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	int val = 5;
	std::cout << val << std::endl;
	Increase(val);
	std::cout << val << std::endl;
	test<int> t(25);
	std::cout << t.GET_DATA() << std::endl;
	test<std::string> tt("Hakan");
	std::cout << tt.GET_DATA() << std::endl;
	return 0;
}
