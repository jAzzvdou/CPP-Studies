#pragma once

# include <iostream>  //| cout
# include <cstdlib>   //| rand, srand
# include <ctime>     //| time

class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{
	public:
		A();
		~A();
};

class B : public Base
{
	public:
		B();
		~B();
};

class C : public Base
{
	public:
		C();
		~C();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

/*

 Exercício 02: Identificação de tipos reais

 Este exercício demonstra o uso de dynamic_cast para identificar o tipo
 real de objetos polimórficos em tempo de execução.

 Funcionalidades principais:
 - Base: classe base com destrutor virtual
 - A, B, C: classes derivadas vazias de Base
 - generate(): cria aleatoriamente uma instância de A, B ou C
 - identify(Base*): identifica o tipo usando ponteiro
 - identify(Base&): identifica o tipo usando referência

 O exercício demonstra RTTI (Run-Time Type Information) sem usar
 std::typeinfo, utilizando dynamic_cast para identificação segura
 de tipos em tempo de execução.

*/
