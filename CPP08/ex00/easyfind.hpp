#pragma once

# include <iostream>  //| cout, cerr
# include <algorithm> //| find, distance
# include <vector>    //| vector
# include <list>      //| list

namespace my
{
	template<typename T>
	int easyfind(T &container, int value)
	{
		typename T::iterator it = std::find(container.begin(), container.end(), value);
		if (it == container.end())
		{
			std::cerr << "Error: Value " << value << " not found" << std::endl;
			return (-1); //| Retorna -1 se o valor não for encontrado
		}
		int position = std::distance(container.begin(), it);
		std::cout << "Value " << value << " found first occurrence at position: " << position << std::endl;
		return (position);
	}
}

/*

 Exercício 00: Easy Find

 Este exercício implementa uma função template easyfind que encontra a primeira ocorrência de um valor inteiro em um container e retorna a posição do valor encontrado.

 Funcionalidades principais:
 - easyfind<T>: função template que aceita um container T e um valor value
 - Retorna a posição do valor encontrado
 - Retorna -1 se o valor não for encontrado
 - Funciona com containers sequenciais vector e list

*/
