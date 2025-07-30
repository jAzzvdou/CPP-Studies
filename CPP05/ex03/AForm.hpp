#pragma once

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm(const AForm &other);

		virtual ~AForm();

		AForm &operator=(const AForm &other);

		const std::string &getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);

		virtual void execute(const Bureaucrat &executor) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class SignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
