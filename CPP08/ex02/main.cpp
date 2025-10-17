#include "MutantStack.hpp"
#include <list>     //| list
#include <iostream> //| cout

int main(void)
{
	{
		std::cout << "RUNNING SUBJECT MAIN" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << "RUNNING ADDITIONAL TESTS" << std::endl;
		MutantStack<int> mutantStack;

		mutantStack.push(10);
		mutantStack.push(20);
		mutantStack.push(30);
		mutantStack.push(40);
		mutantStack.push(50);

		std::cout << "Stack elements using iterators: ";
		for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Stack elements in reverse order: ";
		for (MutantStack<int>::reverse_iterator rit = mutantStack.rbegin(); rit != mutantStack.rend(); ++rit)
		{
			std::cout << *rit << " ";
		}
		std::cout << std::endl;

		const MutantStack<int>& constStack = mutantStack;
		std::cout << "Stack elements using const iterators: ";
		for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
		{
			std::cout << *cit << " ";
		}
		std::cout << std::endl;
	}

	return (0);
}
