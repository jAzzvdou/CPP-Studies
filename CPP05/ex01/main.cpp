#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat jazevedo("jazevedo", 125);
		Bureaucrat aprado("aprado", 100);

		Form project("Pass", 100, 90);
		std::cout << project << std::endl;

		try
		{
			std::cout << jazevedo.getName() << " tenta se passar no projeto.." << std::endl;
			project.beSigned(jazevedo);
		}
	}
	catch (std::exception &e)
	{
	}

	return (0);
}
