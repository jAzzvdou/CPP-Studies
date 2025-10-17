#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n == 0)
		this->_array = NULL;
	else
		this->_array = new T[n];
}

template<typename T>
Array<T>::Array(const Array<T> &other) : _size(other._size)
{
	if (this->_size == 0)
		this->_array = NULL;
	else
	{
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	if (this->_array)
		delete[] this->_array;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		if (this->_array)
			delete[] this->_array;
		
		this->_size = other._size;
		if (this->_size == 0)
			this->_array = NULL;
		else
		{
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = other._array[i];
		}
	}
	return (*this);
}

//| Não const
template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (this->_size == 0)
		throw (Array<T>::EmptyArrayException());
	if (index >= this->_size)
		throw (Array<T>::OutOfBoundsException());
	return (this->_array[index]);
}

//| Const
template<typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (this->_size == 0)
		throw (Array<T>::EmptyArrayException());
	if (index >= this->_size)
		throw (Array<T>::OutOfBoundsException());
	return (this->_array[index]);
}

template<typename T>
unsigned int Array<T>::size() const { return (this->_size); }
