#include "Base.hpp"

int main(void)
{
	std::cout << "Testing type identification with dynamic_cast" << std::endl;
	std::cout << "=============================================" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		Base *ptr = generate();
		
		std::cout << "Test " << (i + 1) << ":" << std::endl;
		std::cout << "Pointer identification: ";
		identify(ptr);
		
		std::cout << "Reference identification: ";
		identify(*ptr);
		
		std::cout << "----------------------------------------" << std::endl;
		
		delete ptr;
	}

	std::cout << "Testing with known types:" << std::endl;
	
	A a;
	std::cout << "A object - Pointer: ";
	identify(&a);
	std::cout << "A object - Reference: ";
	identify(a);
	
	B b;
	std::cout << "B object - Pointer: ";
	identify(&b);
	std::cout << "B object - Reference: ";
	identify(b);
	
	C c;
	std::cout << "C object - Pointer: ";
	identify(&c);
	std::cout << "C object - Reference: ";
	identify(c);

	return (0);
}
