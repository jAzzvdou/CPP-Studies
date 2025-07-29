#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm shrubbery;
	RobotomyRequestForm robotomy;
	PresidentialPardonForm presidential;

	try
	{
		Bureaucrat bureaucrat("jazevedo", 1);

		bureaucrat.signForm(shrubbery);
		bureaucrat.executeForm(shrubbery);

		bureaucrat.signForm(robotomy);
		bureaucrat.executeForm(robotomy);

		bureaucrat.signForm(presidential);
		bureaucrat.executeForm(presidential);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}		
