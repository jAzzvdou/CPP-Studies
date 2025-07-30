#pragma once

# include <iostream>  //| string, cout
# include <exception> //| exception
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);

		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &other);

		const std::string &getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void setGrade(int grade);

		void signForm(AForm &form);
		void executeForm(const AForm &form) const;

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

	private:
		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

/*

 Classe Intern e o padrão de projeto Factory.

 Intern: representa um estagiário que pode criar formulários (AForm) com base em uma string com o nome do formulário.
 - A função makeForm() recebe o nome do formulário e o alvo como argumentos.
 - Dependendo do nome, retorna uma instância de: 
  - ShrubberyCreationForm
  - RobotomyRequestForm
  - PresidentialPardonForm
 - Se o nome for inválido, uma exceção personalizada é lançada.

 - O padrão Factory (ou Factory Method Pattern) é um padrão de projeto criacional que tem como objetivo encapsular a lógica de criação de objetos, permitindo que o código cliente (quem usa) não precise saber qual classe exata está sendo instanciada.

*/
