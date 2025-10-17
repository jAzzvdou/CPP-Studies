#pragma once

# include <iostream>  //| cout
# include <vector>    //| vector
# include <algorithm> //| sort, distance
# include <exception> //| exception

class Span
{
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		
		~Span();

		Span &operator=(const Span &other);
		
		void addNumber(int number);

		template<typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			unsigned int distance = std::distance(begin, end);
			if (size() + distance > capacity())
				throw (Span::SpanFullException());
			this->_numbers.insert(this->_numbers.end(), begin, end);
			std::sort(this->_numbers.begin(), this->_numbers.end());
		}
		
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		unsigned int size() const;
		unsigned int capacity() const;
		void printNumbers() const;
		
		class SpanFullException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		
		class NoSpanException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		std::vector<int> _numbers;
		unsigned int _maxSize;
};

/*

 Exercício 01: Span

 Esta classe implementa um container que armazena números inteiros e calcula o menor e maior span entre eles.

 Funcionalidades principais:
 - Armazena até N números inteiros (N definido no construtor)
 - addNumber(int): adiciona um número individual
 - addNumbers(Iterator, Iterator): adiciona múltiplos números usando iteradores
 - shortestSpan(): encontra o menor span entre números
 - longestSpan(): encontra o maior span entre números
 - Exceções para container cheio e spans impossíveis (menor que 2 números)

 Características:
 - Usa std::vector para armazenamento eficiente
 - Usa algoritmos STL (sort, distance)
 - Suporte para iteradores para adição em massa
 - Tratamento de exceções adequado

*/
