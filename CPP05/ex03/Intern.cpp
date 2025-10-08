#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other)
{
	(void)other; //| Suppress unused parameter warning
	return (*this);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm *form = NULL;
	std::string formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	try
	{
		int i;
		for (i = 0; i < 3; i++)
			if (name == formNames[i])
				break;
		switch (i)
		{
			case 0:
				form = new PresidentialPardonForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new ShrubberyCreationForm(target);
				break;
			default:
				throw FormNotFoundException();
		}
		std::cout << "Intern creates " << name << std::endl;
	}
	catch (const FormNotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (form);
}

const char *Intern::FormNotFoundException::what() const throw() { return ("Intern: form not found"); }
