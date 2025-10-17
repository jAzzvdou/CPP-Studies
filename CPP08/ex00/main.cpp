#include "easyfind.hpp"

int main(void)
{
	std::cout << "Testing easyfind function" << std::endl;
	std::cout << "=========================" << std::endl;

	//| Teste 1: Vetor
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	int value = 3;
	int position = my::easyfind(vec, value);
	std::cout << "Position of value " << value << " is " << position << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	//| Teste 2: Lista
	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	value = 6;
	position = my::easyfind(list, value);
	std::cout << "Position of value " << value << " is " << position << std::endl;

	return (0);
}
