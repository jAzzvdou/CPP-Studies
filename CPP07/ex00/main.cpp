#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl; //| 2
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl; //| 3

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl; //| chaine1
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl; //| chaine2

	return (0);
}
