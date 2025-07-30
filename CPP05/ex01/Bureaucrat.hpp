#pragma once

# include <iostream>  //| string, cout
# include <exception> //| exception
# include "Form.hpp"

class Form;

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

		void signForm(Form &form);

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
		int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

/*

 Implementando uma relação entre duas classes: Bureaucrat e Form.

 Form (formulário): representa um documento que pode ser assinado por um burocrata.
 - Cada formulário tem um nome, um estado (assinado ou não), uma nota mínima para ser assinado (_signGrade) e uma para ser executado (_execGrade).
 - Ao tentar criar um formulário com notas fora do intervalo válido (1 a 150), exceções são lançadas.
 - A função 'beSigned()' permite que um Bureaucrat tente assinar o formulário. Se sua nota for alta o suficiente (<= _signGrade), o formulário é assinado. Caso contrário, uma exceção é lançada.
 - O operador '<<' é usado para mostrar os atributos do Form.

*/
