#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;

	AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
	AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");

	AForm* formInvalid = someRandomIntern.makeForm("banana republic", "Nobody");

	std::cout << std::endl;

	Bureaucrat boss("Alice", 1);

	if (form1)
	{
		std::cout << *form1;
		boss.signForm(*form1);
		boss.executeForm(*form1);
	}
	if (form2)
	{
		std::cout << *form2;
		boss.signForm(*form2);
		boss.executeForm(*form2);
	}
	if (form3)
	{
		std::cout << *form3;
		boss.signForm(*form3);
		boss.executeForm(*form3);
	}

	delete form1;
	delete form2;
	delete form3;
	delete formInvalid;

	return (0);
}
