#include "Bureaucrat.hpp"

int main(void)
{
	//----------| Person 1 |----------//
	try
	{
		Bureaucrat person1("jazevedo", 1);
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
		Bureaucrat person2("btaveira", 150);
		std::cout << person2 << std::endl;

		person2.decrementGrade();
		std::cout << person2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//----------| Person 3 |----------//
	try
	{
		Bureaucrat person1("aprado", 2);
		std::cout << person1 << std::endl;

		person1.incrementGrade();
		std::cout << person1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//----------| Person 4 |----------//
	try
	{
		Bureaucrat person1("jbergfel", 149);
		std::cout << person1 << std::endl;

		person1.decrementGrade();
		std::cout << person1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
