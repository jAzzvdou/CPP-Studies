#pragma once

# include <iostream> //| std::cout

namespace my
{
	template<typename T> void print(T &value) { std::cout << "Value: " << value << std::endl; }

	template<typename T, typename F>
	void iter(T *array, const size_t length, F func)
	{
		if (!array || !func)
			return;
		
		for (size_t i = 0; i < length; i++)
			func(array[i]);
	}
}

/*

 Exercício 01: Função template iter

 Este exercício implementa uma função template iter que aplica uma função a cada elemento de um array.

 Funcionalidades principais:
 - iter<T, F>: função template que recebe um array, seu tamanho e uma função
 - Aplica a função F a cada elemento do array
 - Funciona com qualquer tipo de array e função F compatível

 Características:
 - Verifica se o array e a função F são válidos antes de executar
 - Usa template para funcionar com qualquer tipo de dados
 - A função F pode ser um template instanciado

*/
