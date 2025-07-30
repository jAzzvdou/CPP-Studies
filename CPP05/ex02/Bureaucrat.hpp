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

 Herança, polimorfismo e exceções com a classe abstrata AForm.

 AForm: representa um formulário genérico, que pode ser assinado e executado, mas não define o comportamento de execução (função execute é puramente virtual).
 - AForm possui um nome, estado (assinado ou não), nota mínima para ser assinado (_signGrade) e nota mínima para ser executado (_execGrade).
 - Bureaucrats podem tentar assiná-lo via beSigned(), e se o _grade não for suficiente, uma exceção é lançada.
 - Para ser executado, o formulário precisa estar assinado e o Bureaucrat precisa ter nota suficiente. Caso contrário, exceções também são lançadas.

 Três formulários são implementados, todos herdados de AForm:
 - ShrubberyCreationForm: cria um arquivo com uma árvore ASCII.
 - RobotomyRequestForm: "robotomiza" um alvo, com chance de 50% de sucesso.
 - PresidentialPardonForm: "perdoa" um alvo em nome do presidente.

 Transformar Form em AForm permite tratar os formulários de diferentes maneira, e exceções garante segurança na execução.

*/
