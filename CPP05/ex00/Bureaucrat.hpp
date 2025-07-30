#pragma once

# include <iostream>  //| string, cout
# include <exception> //| exception

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

 Essa lista aborda o conceito de Exceptions (exceções) em C++.
 Aqui, aprendemos a lançar e tratar erros de forma segura e estruturada, usando exceções personalizadas para diferentes situações.

 Bureaucrat (burocrata: indivíduo que trabalha em um sistema hierárquico com regras rígidas).
 - A classe permite criar um burocrata com um nome e uma nota (grade).
 - Ao tentar atribuir uma nota fora do intervalo permitido (1 a 150), exceções são lançadas: GradeTooHighException ou GradeTooLowException.
 - O operador '<<' é usado para mostrar os atributos do Bureaucrat.

*/
