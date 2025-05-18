#include "Bureaucrat.hpp"

int main(void)
{
	//----------| Person 1 |----------//
	try
	{
		Bureaucrat person1("One", 1);
		std::cout << person1 << std::endl;

		person1.incrementGrade();
		std::cout << person1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//----------| Person 2 |----------//
	try
	{
		Bureaucrat person2("Two", 150);
		std::cout << person2 << std::endl;

		person2.decrementGrade();
		std::cout << person2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
