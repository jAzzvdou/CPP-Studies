#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	//| Construtor padrão, inicializa o valor de 'a' como 0.
	Fixed a;
	//| Construtor de cópia, ou seja, copia o valor de 'a' para 'b'.
	Fixed b(a);
	//| Construtor de atribuição, ou seja, copia o valor de 'b' para 'c'.
	Fixed c;
	c = b;

	std::cout << a.getRawBits() << std::endl; //| Resultado: 0.
	std::cout << b.getRawBits() << std::endl; //| Resultado: 0.
	std::cout << c.getRawBits() << std::endl; //| Resultado: 0.
	return (0);
}
