#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("noname"), _grade(150) {}

void handleGradeError(int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade) { handleGradeError(this->_grade); }

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

const std::string &Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::setGrade(int grade)
{
	handleGradeError(grade);
	this->_grade = grade;
}

void Bureaucrat::incrementGrade(void) { setGrade(this->_grade - 1); }

void Bureaucrat::decrementGrade(void) { setGrade(this->_grade + 1); }

const char *Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade too high"); }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade too low"); }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
