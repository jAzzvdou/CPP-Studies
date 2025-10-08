#include <iostream>
#include "Brain.hpp"

std::string fillIdeas(size_t i)
{
	if (i < 20)
		return ("(1)");
	if (i < 40)
		return ("[2]");
	if (i < 60)
		return ("{3}");
	if (i < 80)
		return ("!4!");
	if (i < 100)
		return ("|5|");
	return ("No Idea");
}

Brain::Brain()
{
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = fillIdeas(i);

	std::cout << "@ Brain Default Constructor Called @" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];

	std::cout << "@ Brain Copy Constructor Called @" << std::endl;
}

Brain::~Brain() { std::cout << "@ Brain Destructor Called @" << std::endl; }

Brain &Brain::operator=(const Brain &other)
{
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];

	std::cout << "@ Brain Assignment Constructor Called @" << std::endl;
	return (*this);
}

