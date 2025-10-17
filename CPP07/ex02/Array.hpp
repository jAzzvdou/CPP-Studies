#pragma once

# include <iostream>  //| std::cout
# include <exception> //| std::exception

template<typename T>
class Array
{
	public:
		Array();	
		Array(unsigned int n);
		Array(const Array<T> &other);

		~Array();

		Array<T> &operator=(const Array<T> &other);
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		unsigned int size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("Error <Index out of bounds>"); };
		};

		class EmptyArrayException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("Error <Array is empty>"); };
		};

	private:
		T *_array;
		unsigned int _size;
};

/*

 Exercício 02: Classe Template Array

 Este exercício implementa uma classe template Array que funciona como um array dinâmico genérico.

 Funcionalidades principais:
 - Construtor padrão: cria array vazio
 - Construtor com tamanho: cria array de n elementos inicializados
 - Construtor de cópia e operador de atribuição: cópia profunda
 - Operador []: acesso aos elementos com verificação de limites
 - Função size(): retorna o número de elementos
 - Exceções personalizadas para acesso fora dos limites e array vazio

 Características:
 - Usa new[] para alocação de memória
 - Implementa cópia profunda (deep copy)
 - Verifica limites antes de acessar elementos
 - Funciona com qualquer tipo de dados
 - Segue o Formato Canonical Ortodoxo

*/

# include "Array.tpp" //| Inclusão do arquivo de implementação tem que ser no final do arquivo
