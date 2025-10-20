#pragma once

# include <iostream>  //| cout, cerr
# include <vector>    //| vector
# include <deque>     //| deque
# include <string>    //| string
# include <exception> //| exception
# include <algorithm> //| sort, lower_bound
# include <ctime>     //| clock
# include <cstdlib>   //| atof, atoi
# include <cctype>    //| isdigit

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe(int ac, char **av);
		~PmergeMe();
		
		PmergeMe &operator=(const PmergeMe &other);
		
		template <typename T>
		void printContainer(const T &container);

	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		
		bool validateInput(int ac, char **av);
		
		//| Algoritmos de ordenação Ford-Johnson para vector e deque
		void sortVector();
		void sortDeque();
		
		class InvalidInputException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("Error"); };
		};
};

/*

 Exercício 02: PmergeMe - Ford-Johnson Merge-Insert Sort

 Esta classe implementa o algoritmo de ordenação Ford-Johnson (também conhecido como merge-insertion sort)
 usando dois containers STL diferentes: std::vector e std::deque.

 O que é o algoritmo Ford-Johnson e como funciona o algoritmo?
 
 1. EMPARELHAMENTO: Agrupa os elementos em pares
    - Se houver um número ímpar de elementos, o último fica sem par
    - Exemplo: [5, 2, 8, 1, 9, 3] -> [(5,2), (8,1), (9,3)]
 
 2. COMPARAÇÃO E ORDENAÇÃO DOS PARES: Para cada par, garante que o primeiro é maior que o segundo
    - Compara os elementos de cada par
    - Ordena para que pair.first > pair.second
    - Exemplo: [(5,2), (8,1), (9,3)] -> [(5,2), (8,1), (9,3)]
 
 3. ORDENAÇÃO RECURSIVA DOS MAIORES: Ordena os primeiros elementos de cada par
    - Usa std::sort() nos elementos maiores
    - Exemplo: [5, 8, 9] -> [5, 8, 9]
 
 4. CRIAÇÃO DAS CADEIAS:
    - Main Chain (cadeia principal): primeiros elementos dos pares ordenados
    - Pend Chain (cadeia pendente): segundos elementos dos pares
    - Exemplo: Main = [5, 8, 9], Pend = [2, 1, 3]
 
 5. INSERÇÃO BINÁRIA: Insere elementos da pend chain na main chain usando busca binária
    - Usa std::lower_bound() para encontrar a posição ideal
    - Insere cada elemento da pend chain na posição correta
    - Minimiza comparações através de busca binária
 
 6. TRATAMENTO DO ELEMENTO ÍMPAR: Se houver elemento sem par, insere no final
 
 Exemplo completo: [5, 2, 8, 1, 9, 3]
 
 Passo 1 - Emparelhamento:
   [(5,2), (8,1), (9,3)]
 
 Passo 2 - Ordenação de pares (garantir first > second):
   [(5,2), (8,1), (9,3)] (já estão corretos)
 
 Passo 3 - Ordenação dos maiores elementos:
   [5, 8, 9] (primeiros elementos ordenados)
 
 Passo 4 - Separação em cadeias:
   Main Chain: [5, 8, 9]
   Pend Chain: [2, 1, 3]
 
 Passo 5 - Inserção binária:
   Resultado inicial: [5]
   Inserir 8: [5, 8]
   Inserir 9: [5, 8, 9]
   Inserir 2: [2, 5, 8, 9]
   Inserir 1: [1, 2, 5, 8, 9]
   Inserir 3: [1, 2, 3, 5, 8, 9]
 
 Resultado final: [1, 2, 3, 5, 8, 9]

 Funcionalidades implementadas:
 
 - validateInput(): valida os argumentos de entrada
 - sortVector(): implementa Ford-Johnson para std::vector
 - sortDeque(): implementa Ford-Johnson para std::deque
 - printContainer(): template para exibir o conteúdo dos containers

 IMPORTANTE - Lista CPP09:
 Nesta lista (CPP09), cada exercício deve usar um tipo diferente de container STL.
 Neste exercício (ex02), foram usados std::vector e std::deque para comparar a
 performance do algoritmo Ford-Johnson em diferentes estruturas de dados.
 
 Containers usados na lista:
 - ex00: std::map    (pares chave-valor ordenados)
 - ex01: std::stack  (pilha para avaliação RPN)
 - ex02: std::vector e std::deque (sequências para merge-insert sort)

*/
