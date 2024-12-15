#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>

class Replace
{
	public:
		Replace::Replace(); //| Construtor
		Replace::~Replace(); //| Destrutor

		//|---------| Método |----------|//
		std::string Replace::replace(std::string input, std::string s1, std::string s2);
	private:
};

#endif //| REPLACE_HPP
