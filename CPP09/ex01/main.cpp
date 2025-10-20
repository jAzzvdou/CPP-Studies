#include "RPN.hpp"

int main(int ac, char **argv)
{
	if (ac != 2)
		return (std::cerr << "Usage: " << argv[0] << " \"<RPN_expression>\"" << std::endl, 1);
	
	try
	{
		RPN calculator;
		std::cout << "Input: " << argv[1] << std::endl;
		int result = calculator.evaluate(argv[1]);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
