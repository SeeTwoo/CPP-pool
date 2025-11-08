#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data original;
	original.value = 42;
	original.name = "Hello";

	uintptr_t raw = Serializer::serialize(&original);
	Data *converted = Serializer::deserialize(raw);

	std::cout << "Original pointer : " << &original << std::endl;
	std::cout << "Converted pointer: " << converted << std::endl;

	if (converted == &original)
		std::cout << "Success: Pointers match." << std::endl;
	else
		std::cout << "Error: Pointers differ." << std::endl;

	std::cout << "Value: " << converted->value << std::endl;
	std::cout << "Name : " << converted->name << std::endl;

	return 0;
}
