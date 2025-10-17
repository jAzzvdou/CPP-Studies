#include "Array.hpp"

int main(void)
{
	std::cout << "Testing Array template class" << std::endl;
	std::cout << "===========================" << std::endl;

	//| Teste 1: Construtor padrão (vazio)
	std::cout << "1. Testing default constructor:" << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	//| Teste 2: Construtor com tamanho
	std::cout << "2. Testing constructor with size:" << std::endl;
	Array<int> intArray(5);
	std::cout << "Int array size: " << intArray.size() << std::endl;
	
	//| Teste 3: Colocando elementos no array
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i * 10;
	
	std::cout << "Array elements: ";
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	//| Construtor de cópia
	std::cout << "3. Testing copy constructor:" << std::endl;
	Array<int> copiedArray(intArray);
	std::cout << "Copied array size: " << copiedArray.size() << std::endl;
	std::cout << "Copied array elements: ";
	for (unsigned int i = 0; i < copiedArray.size(); i++)
		std::cout << copiedArray[i] << " ";
	std::cout << std::endl;
	
	//| Modificação do array original
	intArray[0] = 999;
	std::cout << "After modifying original array:" << std::endl;
	std::cout << "Original array[0]: " << intArray[0] << std::endl;
	std::cout << "Copied array[0]: " << copiedArray[0] << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	//| Teste 4: Operador de atribuição
	std::cout << "4. Testing assignment operator:" << std::endl;
	Array<int> assignedArray;
	assignedArray = intArray;
	std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
	std::cout << "Assigned array elements: ";
	for (unsigned int i = 0; i < assignedArray.size(); i++)
		std::cout << assignedArray[i] << " ";
	std::cout << std::endl;
	
	//| Modificação do array original
	intArray[1] = 888;
	std::cout << "After modifying original array:" << std::endl;
	std::cout << "Original array[1]: " << intArray[1] << std::endl;
	std::cout << "Assigned array[1]: " << assignedArray[1] << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	//| Teste 5: Array de strings
	std::cout << "5. Testing with string array:" << std::endl;
	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "C++";
	
	std::cout << "String array elements:" << std::endl;
	for (unsigned int i = 0; i < stringArray.size(); i++)
		std::cout << "[" << i << "] = " << stringArray[i] << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	//| Teste 6: Exceção de índice fora dos limites
	std::cout << "6. Testing out of bounds exception:" << std::endl;
	try
	{
		std::cout << "Accessing valid index: " << intArray[2] << std::endl;
		std::cout << "Accessing invalid index: " << intArray[10] << std::endl;
	}
	catch (const Array<int>::OutOfBoundsException &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;

	//| Testando com outros tipos de dados
	std::cout << "7. Testing with other types of data:" << std::endl;
	Array<double> doubleArray(3);
	doubleArray[0] = 1.1;
	doubleArray[1] = 2.2;
	doubleArray[2] = 3.3;
	std::cout << "Double array elements: ";
	for (unsigned int i = 0; i < doubleArray.size(); i++)
		std::cout << doubleArray[i] << " ";
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	Array<char> charArray(4);
	charArray[0] = 'A';
	charArray[1] = 'B';
	charArray[2] = 'C';
	charArray[3] = 'D';
	std::cout << "Char array elements: ";
	for (unsigned int i = 0; i < charArray.size(); i++)
		std::cout << charArray[i] << " ";
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	return (0);
}
