#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe::PmergeMe(int ac, char **av)
{
	if (!validateInput(ac, av)) //| Validando o input
		throw InvalidInputException();
	
	std::cout << "Before: ";
	printContainer(this->_vector);
	
	//| Ordenando com o deque e medindo o tempo em microsegundos
	clock_t startDeque = clock();
	sortDeque();
	clock_t endDeque = clock();
	double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;
	
	//| Ordenando com o vector e medindo o tempo em microsegundos
	clock_t startVector = clock();
	sortVector();
	clock_t endVector = clock();
	double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "After: ";
	printContainer(this->_deque);
	
	std::cout << "Time to process a range of " << this->_deque.size() 
			  << " elements with std::deque  : " << timeDeque << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_vector.size() 
			  << " elements with std::vector : " << timeVector << " us" << std::endl;
	
	if (this->_deque == std::deque<int>(this->_vector.begin(), this->_vector.end()))
		std::cout << "The sorted sequences are equal." << std::endl;
	else
		std::cout << "The sorted sequences are not equal." << std::endl;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return *this;
}

template <typename T>
void PmergeMe::printContainer(const T &container)
{
	typename T::const_iterator it = container.begin();
	for (; it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template void PmergeMe::printContainer<std::vector<int> >(const std::vector<int> &);
template void PmergeMe::printContainer<std::deque<int> >(const std::deque<int> &);

bool PmergeMe::validateInput(int ac, char **av)
{
	if (ac < 2)
		return (false);
	
	for (int i = 1; i < ac; ++i)
	{
		std::string str = av[i];
		if (str.empty())
			return (false);
		
		for (size_t j = 0; j < str.length(); ++j)
			if (!std::isdigit(str[j]))
				return (false);
		
		double tmp = std::strtod(av[i], NULL);
		if (tmp <= 0 || tmp > 2147483647) //| Somente números positivos e sem overflow
			return (false);
		
		int value = static_cast<int>(tmp);
		this->_vector.push_back(value);
		this->_deque.push_back(value);
	}
	
	return (true);
}

//| Algoritmo Ford-Johnson para std::deque
void PmergeMe::sortDeque()
{
	if (this->_deque.size() <= 1)
		return;
	
	//| 1. Criando pares e tratando o elemento ímpar
	std::deque<std::pair<int, int> > pairs;
	int unpaired = -1;
	
	//| Salvando o elemento ímpar se o tamanho for ímpar
	if (this->_deque.size() % 2 != 0)
	{
		unpaired = this->_deque.back();
		this->_deque.pop_back();
	}
	
	//| 2. Criando pares garantindo que o primeiro seja maior que o segundo
	for (size_t i = 0; i < this->_deque.size(); i += 2)
	{
		if (i + 1 < this->_deque.size())
		{
			if (this->_deque[i] < this->_deque[i + 1])
				pairs.push_back(std::make_pair(this->_deque[i + 1], this->_deque[i]));
			else
				pairs.push_back(std::make_pair(this->_deque[i], this->_deque[i + 1]));
		}
	}
	
	//| 3. Ordenando os pares pelo primeiro elemento (o maior)
	std::deque<std::pair<int, int> > sortedPairs = pairs;
	std::sort(sortedPairs.begin(), sortedPairs.end());
	
	//| 4. Separando em cadeia principal (elementos maiores) e cadeia pendente (elementos menores)
	std::deque<int> mainChain;
	std::deque<int> pendChain;
	
	for (size_t i = 0; i < sortedPairs.size(); ++i)
	{
		mainChain.push_back(sortedPairs[i].first);
		pendChain.push_back(sortedPairs[i].second);
	}
	
	//| 5. Construindo o resultado começando com o primeiro elemento da cadeia principal
	std::deque<int> result;
	if (!mainChain.empty())
		result.push_back(mainChain[0]);
	
	//| 6. Inserindo os elementos restantes da cadeia principal usando busca binária
	for (size_t i = 1; i < mainChain.size(); ++i)
	{
		std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[i]);
		result.insert(pos, mainChain[i]);
	}
	
	//| 7. Inserindo os elementos da cadeia pendente usando busca binária
	for (size_t i = 0; i < pendChain.size(); ++i)
	{
		std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[i]);
		result.insert(pos, pendChain[i]);
	}
	
	//| 8. Inserindo o elemento ímpar se ele existir
	if (unpaired != -1)
	{
		std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), unpaired);
		result.insert(pos, unpaired);
	}
	
	//| Atualizando o deque com o resultado ordenado
	this->_deque = result;
}

//| Algoritmo Ford-Johnson para std::vector
void PmergeMe::sortVector()
{
	if (this->_vector.size() <= 1)
		return;
	
	//| 1. Criando pares e tratando o elemento ímpar
	std::vector<std::pair<int, int> > pairs;
	int unpaired = -1;
	
	//| Salvando o elemento ímpar se o tamanho for ímpar
	if (this->_vector.size() % 2 != 0)
	{
		unpaired = this->_vector.back();
		this->_vector.pop_back();
	}
	
	//| 2. Criando pares garantindo que o primeiro seja maior que o segundo
	for (size_t i = 0; i < this->_vector.size(); i += 2)
	{
		if (i + 1 < this->_vector.size())
		{
			if (this->_vector[i] < this->_vector[i + 1])
				pairs.push_back(std::make_pair(this->_vector[i + 1], this->_vector[i]));
			else
				pairs.push_back(std::make_pair(this->_vector[i], this->_vector[i + 1]));
		}
	}
	
	//| 3. Ordenando os pares pelo primeiro elemento (o maior)
	std::vector<std::pair<int, int> > sortedPairs = pairs;
	std::sort(sortedPairs.begin(), sortedPairs.end());
	
	//| 4. Separando em cadeia principal (elementos maiores) e cadeia pendente (elementos menores)
	std::vector<int> mainChain;
	std::vector<int> pendChain;
	
	for (size_t i = 0; i < sortedPairs.size(); ++i)
	{
		mainChain.push_back(sortedPairs[i].first);
		pendChain.push_back(sortedPairs[i].second);
	}
	
	//| 5. Construindo o resultado começando com o primeiro elemento da cadeia principal
	std::vector<int> result;
	if (!mainChain.empty())
		result.push_back(mainChain[0]);
	
	//| 6. Inserindo os elementos restantes da cadeia principal usando busca binária
	for (size_t i = 1; i < mainChain.size(); ++i)
	{
		std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[i]);
		result.insert(pos, mainChain[i]);
	}
	
	//| 7. Inserindo os elementos da cadeia pendente usando busca binária
	for (size_t i = 0; i < pendChain.size(); ++i)
	{
		std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[i]);
		result.insert(pos, pendChain[i]);
	}
	
	//| 8. Inserindo o elemento ímpar se ele existir
	if (unpaired != -1)
	{
		std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), unpaired);
		result.insert(pos, unpaired);
	}
	
	//| Atualizando o vector com o resultado ordenado
	this->_vector = result;
}
