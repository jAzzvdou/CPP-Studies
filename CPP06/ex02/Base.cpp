#include "Base.hpp"

Base::~Base() {}

A::A() {}

A::~A() {}

B::B() {}

B::~B() {}

C::C() {}

C::~C() {}

Base *generate(void)
{
	static bool initialized = false;
	if (!initialized)
	{
		std::srand(std::time(NULL));
		initialized = true;
	}
	int random = std::rand() % 3;
	
	switch (random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (new A());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) //| Se falhou é porque não é A.
	{
		//| Não fazer nada, apenas continuar o programa.
	}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) //| Se falhou é porque não é B.
	{
		//| Não fazer nada, apenas continuar o programa.
	}
	
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) //| Se falhou é porque não é C.
	{
		//| Não fazer nada, apenas continuar o programa.
	}
	
	std::cout << "Unknown type" << std::endl;
}
