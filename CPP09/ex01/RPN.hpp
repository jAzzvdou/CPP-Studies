#pragma once

# include <iostream>  //| cout, cerr
# include <string>    //| string
# include <stack>     //| stack
# include <sstream>   //| stringstream
# include <exception> //| exception
# include <stdexcept> //| runtime_error

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		~RPN();
		
		RPN &operator=(const RPN &other);
		
		bool isOperator(char c) const;
		bool isDigit(char c) const;
		int evaluate(const std::string &expression);
		int performOperation(int a, int b, char op) const;
		
		class InvalidExpressionException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		
		class DivisionByZeroException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		std::stack<int> _operands;
		
		void clearStack();
		bool isValidToken(char c) const;
};

/*

 Exercício 01: Reverse Polish Notation (RPN)

 Esta classe implementa uma calculadora que avalia expressões matemáticas em notação polonesa reversa (RPN).

 O que é notação polonesa reversa?
 
 A Notação Polonesa Reversa (RPN), também conhecida como notação pós-fixada, é um sistema matemático onde
 os operadores são colocados APÓS os operandos, ao contrário da notação infixa tradicional.
 
 Exemplos de conversão:
 - Infixa:  (3 + 4)         →  RPN: 3 4 +
 - Infixa:  (5 * 2)         →  RPN: 5 2 *
 - Infixa:  (8 - 3) * 2     →  RPN: 8 3 - 2 *
 - Infixa:  (1 + 2) * 4     →  RPN: 1 2 + 4 *
 
 Vantagens da RPN:
 - Não precisa de parênteses para definir precedência
 - Avaliação é feita da esquerda para a direita
 - Implementação simples usando uma pilha (stack)
 - Muito eficiente para processamento computacional

 Como funciona o algoritmo RPN?
 
 O algoritmo segue três regras simples:
 
 1. Se o token é um NÚMERO:
    - Empilhe (push) o número na pilha
 
 2. Se o token é um OPERADOR (+, -, *, /):
    - Desempilhe (pop) dois números da pilha
    - Aplique a operação: primeiro_desempilhado operador segundo_desempilhado
    - Empilhe o resultado na pilha
 
 3. Ao final:
    - A pilha deve conter EXATAMENTE um número (o resultado final)
 
 Exemplo passo a passo: "3 4 + 2 *"
 
 Token | Ação                    | Pilha
 ------|-------------------------|--------
 3     | Push 3                  | [3]
 4     | Push 4                  | [3, 4]
 +     | Pop 4, Pop 3, Push 7    | [7]
 2     | Push 2                  | [7, 2]
 *     | Pop 2, Pop 7, Push 14   | [14]
 
 Resultado final: 14
 
 Funcionalidades principais:
 
 - evaluate(expression): método principal que avalia a expressão RPN completa
 - performOperation(a, b, op): executa uma operação aritmética
 - isOperator(c): verifica se um caractere é um operador válido
 - isDigit(c): verifica se um caractere é um dígito (0-9)
 - isValidToken(c): valida se um token é válido (dígito, operador ou espaço)
 - clearStack(): limpa a pilha para avaliação de nova expressão
 - InvalidExpressionException: lançada quando a expressão é inválida
 - DivisionByZeroException: lançada quando há tentativa de divisão por zero

 IMPORTANTE - Lista CPP09:
 Nesta lista (CPP09), cada exercício deve usar um tipo diferente de container STL.
 Neste exercício (ex01), foi usado o std::stack

*/
