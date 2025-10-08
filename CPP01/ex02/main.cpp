#include <iostream>

int	main(void)
{
	//| String.
	std::string str = "HI THIS IS BRAIN";
	//| Ponteiro para string.
	std::string *stringPTR = &str;
	//| Referência para string.
	std::string &stringREF = str;

	//| Printa a string.
	std::cout << "string: " << str << std::endl;
	//| Printa o ponteiro para a string.
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	//| Printa a referência para a string.
	std::cout << "stringREF: " << stringREF << std::endl;

	return (0);
}
