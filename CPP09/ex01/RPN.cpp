#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _operands(other._operands) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->_operands = other._operands;
	return (*this);
}

int RPN::evaluate(const std::string &expression)
{
	clearStack();
	
	if (expression.empty())
		throw (RPN::InvalidExpressionException());
	
	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];
		
		if (c == ' ') //| Pulando os espaços
			continue;
		
		if (!isValidToken(c)) //| Validando o token
			throw (RPN::InvalidExpressionException());
		
		if (isDigit(c)) //| Validando se o token é um dígito
			this->_operands.push(c - '0');
		else if (isOperator(c)) //| Validando se o token é um operador (+, -, *, /)
		{
			if (this->_operands.size() < 2)
				throw (RPN::InvalidExpressionException());
			
			int b = this->_operands.top();
			this->_operands.pop();
			int a = this->_operands.top();
			this->_operands.pop();
			
			int result = performOperation(a, b, c);
			this->_operands.push(result);
		}
	}
	
	if (this->_operands.size() != 1)
		throw (RPN::InvalidExpressionException());
	
	return (this->_operands.top());
}

bool RPN::isOperator(char c) const { return (c == '+' || c == '-' || c == '*' || c == '/'); }

bool RPN::isDigit(char c) const { return (c >= '0' && c <= '9'); }

int RPN::performOperation(int a, int b, char op) const
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw (RPN::DivisionByZeroException());
			return (a / b);
		default:
			throw (RPN::InvalidExpressionException());
	}
}

void RPN::clearStack()
{
	while (!this->_operands.empty())
		this->_operands.pop();
}

bool RPN::isValidToken(char c) const { return (isDigit(c) || isOperator(c) || c == ' '); }

const char *RPN::InvalidExpressionException::what() const throw() { return ("Error: Invalid expression"); }

const char *RPN::DivisionByZeroException::what() const throw() { return ("Error: Division by zero"); }
