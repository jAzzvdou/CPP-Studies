#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main(void)
{
	size_t n = 10;
	size_t half = n / 2;

	Animal *animals[n];

	for (size_t i = 0; i < half ; i++)
		animals[i] = new Cat();
	for (size_t i = half; i < n; i++)
		animals[i] = new Dog();

	std::cout << std::endl;

	Cat *cat = new Cat();
	Cat *newCat = new Cat(*cat);

	delete cat;
	delete newCat;

	std::cout << std::endl;

	for (size_t i = 0; i < n; i++)
		delete animals[i];

	return (0);
}
