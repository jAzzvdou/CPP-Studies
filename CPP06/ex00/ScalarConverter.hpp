#pragma once

# include <iostream> //| string, cout
# include <string>   //| string
# include <limits>   //| numeric_limits
# include <cstdlib>  //| strtod, strtof
# include <cmath>    //| isnan, isinf

class ScalarConverter
{
	public:
		static void convert(const std::string &literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &other);

		static bool isChar(const std::string &literal);
		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);
		static bool isSpecialFloat(const std::string &literal);
		static bool isSpecialDouble(const std::string &literal);

		static void convertFromChar(char c);
		static void convertFromInt(int i);
		static void convertFromFloat(float f);
		static void convertFromDouble(double d);
		static void convertFromSpecialFloat(const std::string &literal);
		static void convertFromSpecialDouble(const std::string &literal);

		static void displayChar(char c);
		static void displayInt(int i);
		static void displayFloat(float f);
		static void displayDouble(double d);
};

/*

 Exercício 00: Conversão de tipos escalares

 Este exercício implementa uma classe ScalarConverter que converte uma string
 representando um literal C++ para os tipos escalares: char, int, float e double.

 Funcionalidades principais:
 - Detecta automaticamente o tipo do literal de entrada
 - Converte para todos os tipos escalares possíveis
 - Trata casos de inf, -inf, nan para float e double
 - Exibe mensagens adequadas quando a conversão não é possível
 - Tratamento de overflow e underflow

*/
