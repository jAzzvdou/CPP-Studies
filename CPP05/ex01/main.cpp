#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form form("OnlyMandatoryPart", 100, 125);
	std::cout << form << std::endl;

	//----------| Person 1 |----------//
	try
	{
		Bureaucrat person1("jazevedo", 125);
		person1.signForm(form);

		std::cout << person1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//----------| Person 2 |----------//
	try
	{
		Bureaucrat person2("jbergfel", 115);
		person2.signForm(form);

		std::cout << person2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//----------| Person 3 |----------//
	try
	{
		Bureaucrat person3("aprado", 100);
		person3.signForm(form);

		std::cout << person3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//----------| Person 4 |----------//
	try
	{
		Bureaucrat person4("btaveira", 80);
		person4.signForm(form);

		std::cout << person4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
