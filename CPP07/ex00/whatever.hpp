#pragma once

# include <iostream> //| std::cout

template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T min(const T &a, const T &b) { return (a < b ? a : b); }

template<typename T>
T max(const T &a, const T &b) { return (a > b ? a : b); }

/*

 Exercício 00: Funções templates

 Este exercício implementa três funções templates básicas que demonstram o conceito de templates em C++.

 - swap<T>: troca os valores de dois parâmetros do mesmo tipo
 - min<T>: retorna o menor valor entre dois parâmetros
 - max<T>: retorna o maior valor entre dois parâmetros

 Características:
 - As funções são templates, funcionando com qualquer tipo que suporte operadores de comparação
 - Se os valores forem iguais, min e max retornam o segundo parâmetro

*/
