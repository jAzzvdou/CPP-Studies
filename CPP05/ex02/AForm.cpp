#include "AForm.hpp"

AForm::AForm(): _name("noname"), _signed(false), _signGrade(1), _execGrade(1) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw (AForm::GradeTooHighException());
    if (signGrade > 150 || execGrade > 150)
        throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &other): _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
 	   this->_signed = other._signed;
    return (*this);
}

const std::string &AForm::getName() const { return (this->_name); }

bool AForm::getSigned() const { return (this->_signed); }

int AForm::getSignGrade() const { return (this->_signGrade); }

int AForm::getExecGrade() const { return (this->_execGrade); }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (this->_signed)
		throw (AForm::SignedException());
    if (bureaucrat.getGrade() > this->_signGrade)
        throw (AForm::GradeTooLowException());
    this->_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->_execGrade)
		throw (AForm::GradeTooLowException());
}

const char *AForm::GradeTooHighException::what() const throw() { return ("Grade is too high"); }

const char *AForm::GradeTooLowException::what() const throw() { return ("Grade is too low"); }

const char *AForm::SignedException::what() const throw() { return ("Form is already signed"); }

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm name: " << form.getName() << "\n"
        << "AForm signed: " << (form.getSigned() ? "yes" : "no") << "\n"
        << "AForm sign grade: " << form.getSignGrade() << "\n"
        << "AForm exec grade: " << form.getExecGrade() << std::endl;
    return (os);
}
