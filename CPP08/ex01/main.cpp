#include "Span.hpp"
#include <ctime>   //| time
#include <cstdlib> //| rand

int main(void)
{
	try //| Forçando a exceção SpanFullException
	{
		Span span(5);
		span.addNumber(1);
		span.addNumber(2);
		span.addNumber(3);
		span.addNumber(4);
		span.addNumber(5);
		span.addNumber(6);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try //| Forçando a exceção NoSpanException
	{
		Span span2(5);
		span2.addNumber(1);
		std::cout << span2.shortestSpan() << std::endl;
		std::cout << span2.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try //| Execução normal
	{
		Span span3(5);
		span3.addNumber(1);
		span3.addNumber(2);
		span3.addNumber(3);
		span3.addNumber(4);
		span3.addNumber(5);
		span3.printNumbers();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try //| Execução normal muitos números
	{
		int n = 42000;
		Span span4(n);
		std::vector<int> numbers;
		std::srand(std::time(NULL));
		for (int i = 0; i < n; i++)
			numbers.push_back(std::rand());
		span4.addNumbers(numbers.begin(), numbers.end());
		std::cout << span4.shortestSpan() << std::endl;
		std::cout << span4.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
