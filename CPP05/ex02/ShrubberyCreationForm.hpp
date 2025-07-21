#pragma once

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		virtual void execute(const Bureaucrat &executor) const;

		class FileNotOpenException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string _target;
};
