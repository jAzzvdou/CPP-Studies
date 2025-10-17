#pragma once

# include <stack>     //| stack

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack<T> &other);
		~MutantStack();
		MutantStack<T> &operator=(const MutantStack<T> &other);
			
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
		
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

/*

 Exercício 02: MutantStack

 Esta classe implementa uma versão iterável do std::stack, adicionando funcionalidade de iteradores que não existem na implementação padrão.

 Funcionalidades principais:
 - Herda todas as funcionalidades do std::stack
 - Adiciona iteradores begin(), end(), rbegin(), rend()
 - Suporta iteração normal e reversa

*/

# include "MutantStack.tpp"
