#include "Form.hpp"

Form::Form(): _name("noname"), _signed(false), _signGrade(1), _execGrade(1) {}

Form::Form(const std::string &name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw (Form::GradeTooHighException());
    if (signGrade > 150 || execGrade > 150)
        throw (Form::GradeTooLowException());
}

Form::Form(const Form &other): _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
    	this->_signed = other._signed;
    return (*this);
}

const std::string &Form::getName() const { return (this->_name); }

bool Form::getSigned() const { return (this->_signed); }

int Form::getSignGrade() const { return (this->_signGrade); }

int Form::getExecGrade() const { return (this->_execGrade); }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw (Form::GradeTooLowException());
    this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() { return ("Grade is too high"); }

const char *Form::GradeTooLowException::what() const throw() { return ("Grade is too low"); }

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form name: " << form.getName() << "\n"
    	<< "Form signed: " << (form.getSigned() ? "yes" : "no") << "\n"
        << "Form sign grade: " << form.getSignGrade() << "\n"
        << "Form exec grade: " << form.getExecGrade() << std::endl;
    return (os);
}
