#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137), _target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);

	std::string filename = this->_target + "_shrubbery";
	std::ofstream file;
	file.open(filename.c_str(), std::ios::out);
	if (!file.is_open())
		throw (FileNotOpenException());
	file << "       /\\\n";
	file << "      /**\\\n";
	file << "     /****\\\n";
	file << "    /******\\\n";
	file << "   /********\\\n";
	file << "       ||\n";
	file.close();
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw() { return ("Error: file could not be opened."); }
