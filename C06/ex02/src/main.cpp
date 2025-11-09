#include <iostream>
#include <ctime>
#include <cstdlib>
#include "functions.hpp"

int main()
{
	std::srand(std::time(0));

	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);

	delete ptr;
	return 0;
}
