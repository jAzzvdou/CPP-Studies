#pragma once

# include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(const std::string &name, int signGrade, int execGrade);
		Form(const Form &other);

		~Form();

		Form &operator=(const Form &other);

		const std::string &getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);
