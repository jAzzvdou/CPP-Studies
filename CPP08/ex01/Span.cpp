#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n): _maxSize(n) { this->_numbers.reserve(n); }

Span::Span(const Span &other): _numbers(other._numbers), _maxSize(other._maxSize) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_numbers = other._numbers;
		this->_maxSize = other._maxSize;
	}
	return (*this);
}

void Span::addNumber(int number)
{
	if (size() >= capacity())
		throw (Span::SpanFullException());
	this->_numbers.push_back(number);
	std::sort(this->_numbers.begin(), this->_numbers.end());
}

unsigned int Span::shortestSpan() const
{
	if (size() < 2)
		throw (Span::NoSpanException());

	//| Encontra a menor diferença entre dois números adjacentes
	unsigned int minDiff = (unsigned int)(this->_numbers[1] - this->_numbers[0]);
	for (size_t i = 1; i < this->_numbers.size(); ++i)
	{
		unsigned int diff = static_cast<unsigned int>(this->_numbers[i] - this->_numbers[i - 1]);
		if (diff < minDiff)
			minDiff = diff;
	}
	return (minDiff);
}

unsigned int Span::longestSpan() const
{
	if (size() < 2)
		throw (Span::NoSpanException());

	//| Encontra a maior diferença entre o primeiro e o último número
	return (static_cast<unsigned int>(this->_numbers.back() - this->_numbers.front()));
}

unsigned int Span::size() const { return (this->_numbers.size()); }

unsigned int Span::capacity() const { return (this->_maxSize); }

void Span::printNumbers() const
{
	size_t sz = size();
	for (size_t i = 0; i < sz; i++)
		std::cout << this->_numbers[i] << std::endl;
}

const char *Span::SpanFullException::what() const throw() { return ("Span is full or the number of numbers to add is greater than the capacity"); }

const char *Span::NoSpanException::what() const throw() { return ("No span can be found or the number of numbers is less than 2"); }
