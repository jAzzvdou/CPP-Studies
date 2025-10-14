#include "Serializer.hpp"

int main(void)
{
	Data originalData;
	originalData.value = 42;
	originalData.name = "Test Data";
	originalData.price = 99.99;
	originalData.isActive = true;

	std::cout << "Original Data:" << std::endl;
	std::cout << "Value: " << originalData.value << std::endl;
	std::cout << "Name: " << originalData.name << std::endl;
	std::cout << "Price: " << originalData.price << std::endl;
	std::cout << "Is Active: " << (originalData.isActive ? "true" : "false") << std::endl;
	std::cout << "Address: " << &originalData << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized value: " << serialized << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	Data* deserializedData = Serializer::deserialize(serialized);
	
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "Value: " << deserializedData->value << std::endl;
	std::cout << "Name: " << deserializedData->name << std::endl;
	std::cout << "Price: " << deserializedData->price << std::endl;
	std::cout << "Is Active: " << (deserializedData->isActive ? "true" : "false") << std::endl;
	std::cout << "Address: " << deserializedData << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	if (&originalData == deserializedData)
		std::cout << "SUCCESS: Original and deserialized pointers are equal!" << std::endl;
	else
		std::cout << "ERROR: Pointers are not equal!" << std::endl;

	return (0);
}
