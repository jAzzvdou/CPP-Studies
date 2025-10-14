#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "Error: Empty string" << std::endl;
		return;
	}

	if (isSpecialFloat(literal))
	{
		convertFromSpecialFloat(literal);
		return;
	}

	if (isSpecialDouble(literal))
	{
		convertFromSpecialDouble(literal);
		return;
	}

	if (isChar(literal))
	{
		convertFromChar(literal[0]);
		return;
	}

	if (isInt(literal))
	{
		char *end;
		long intValue = std::strtol(literal.c_str(), &end, 10);
		if (*end == '\0' && intValue >= std::numeric_limits<int>::min() && intValue <= std::numeric_limits<int>::max())
			convertFromInt(static_cast<int>(intValue));
		else
			std::cout << "Error: Integer overflow" << std::endl;
		return;
	}

	if (isFloat(literal))
	{
		char *end;
		float floatValue = std::strtof(literal.c_str(), &end);
		if (*end == 'f' && *(end + 1) == '\0')
			convertFromFloat(floatValue);
		else
			std::cout << "Error: Invalid float format" << std::endl;
		return;
	}

	if (isDouble(literal))
	{
		char *end;
		double doubleValue = std::strtod(literal.c_str(), &end);
		if (*end == '\0')
			convertFromDouble(doubleValue);
		else
			std::cout << "Error: Invalid double format" << std::endl;
		return;
	}

	std::cout << "Error: Invalid literal format" << std::endl; //| Se não for nenhum dos tipos acima, retorna um erro
}

bool ScalarConverter::isChar(const std::string &literal) 
{ 
	if (literal.length() != 1)
		return false;
	char c = literal[0];
	return (c >= 32 && c <= 126 && !std::isdigit(c)); 
}

bool ScalarConverter::isInt(const std::string &literal)
{
	if (literal.empty())
		return (false);
	
	size_t start = 0;
	if (literal[0] == '-' || literal[0] == '+')
		start = 1;
	
	if (start >= literal.length())
		return (false);
	
	for (size_t i = start; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return (false);
	
	std::string withoutF = literal.substr(0, literal.length() - 1);
	if (withoutF.empty())
		return (false);
	
	bool hasDot = false;
	size_t start = 0;
	if (withoutF[0] == '-' || withoutF[0] == '+')
		start = 1;
	
	if (start >= withoutF.length())
		return (false);
	
	for (size_t i = start; i < withoutF.length(); i++)
	{
		if (withoutF[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (!std::isdigit(withoutF[i]))
			return (false);
	}
	return hasDot;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	if (literal.empty())
		return (false);
	
	bool hasDot = false;
	size_t start = 0;
	if (literal[0] == '-' || literal[0] == '+')
		start = 1;
	
	if (start >= literal.length())
		return (false);
	
	for (size_t i = start; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return (false);
	}
	return (hasDot);
}

bool ScalarConverter::isSpecialFloat(const std::string &literal) { return (literal == "-inff" || literal == "+inff" || literal == "nanf"); }

bool ScalarConverter::isSpecialDouble(const std::string &literal) { return (literal == "-inf" || literal == "+inf" || literal == "nan"); }

void ScalarConverter::convertFromChar(char c)
{
	displayChar(c);
	displayInt(static_cast<int>(c));
	displayFloat(static_cast<float>(c));
	displayDouble(static_cast<double>(c));
}

void ScalarConverter::convertFromInt(int i)
{
	displayChar(static_cast<char>(i));
	displayInt(i);
	displayFloat(static_cast<float>(i));
	displayDouble(static_cast<double>(i));
}

void ScalarConverter::convertFromFloat(float f)
{
	displayChar(static_cast<char>(f));
	displayInt(static_cast<int>(f));
	displayFloat(f);
	displayDouble(static_cast<double>(f));
}

void ScalarConverter::convertFromDouble(double d)
{
	displayChar(static_cast<char>(d));
	displayInt(static_cast<int>(d));
	displayFloat(static_cast<float>(d));
	displayDouble(d);
}

void ScalarConverter::convertFromSpecialFloat(const std::string &literal)
{
	float f;
	if (literal == "-inff")
		f = -std::numeric_limits<float>::infinity();
	else if (literal == "+inff")
		f = std::numeric_limits<float>::infinity();
	else
		f = std::numeric_limits<float>::quiet_NaN();
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertFromSpecialDouble(const std::string &literal)
{
	double d;
	if (literal == "-inf")
		d = -std::numeric_limits<double>::infinity();
	else if (literal == "+inf")
		d = std::numeric_limits<double>::infinity();
	else
		d = std::numeric_limits<double>::quiet_NaN();
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::displayChar(char c)
{
	if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::displayInt(int i) { std::cout << "int: " << i << std::endl; }

void ScalarConverter::displayFloat(float f) 
{ 
	if (std::isnan(f) || std::isinf(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;
}

void ScalarConverter::displayDouble(double d) 
{ 
	if (std::isnan(d) || std::isinf(d))
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}
