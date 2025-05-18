#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("noname"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->_grade = other._grade;
	return (*this);
}

const std::string &Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade too high"); }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade too low"); }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
