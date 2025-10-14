#pragma once

# include <iostream>  //| cout
# include <stdint.h>  //| uintptr_t

struct Data
{
	int			value;
	std::string	name;
	double		price;
	bool		isActive;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);		//| Converte um ponteiro Data* para uintptr_t
		static Data* deserialize(uintptr_t raw);	//| Converte um uintptr_t de volta para Data*

	private:
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();

		Serializer &operator=(const Serializer &other);
};

/*

 Exercício 01: Serialização

 Este exercício implementa uma classe Serializer que converte ponteiros para
 uintptr_t (inteiro sem sinal) e vice-versa, demonstrando o uso de casting
 de ponteiros.

 Funcionalidades principais:
 - serialize(): converte um ponteiro Data* para uintptr_t
 - deserialize(): converte um uintptr_t de volta para Data*
 - A classe é não-instanciável (apenas métodos estáticos)
 - Demonstra conversão segura de ponteiros para inteiros e vice-versa

 A estrutura Data contém dados diversos para demonstrar a funcionalidade
 de serialização/deserialização.

*/
