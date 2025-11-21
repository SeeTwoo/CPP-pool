#include <iostream>
#include "Array.hpp"

int main()
{
	// Test 1: Empty array
	Array<int> a;
	std::cout << "a.size() = " << a.size() << std::endl;

	// Test 2: Array of 5 ints (default-initialized)
	Array<int> b(5);
	for (unsigned i = 0; i < b.size(); ++i)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;

	// Test 3: Write to array
	for (unsigned i = 0; i < b.size(); ++i)
		b[i] = i * 10;

	// Test 4: Copy constructor
	Array<int> c(b);
	b[0] = 999;
	std::cout << "b[0] = " << b[0] << ", c[0] = " << c[0] << std::endl;

	// Test 5: Assignment operator
	Array<int> d;
	d = b;
	b[1] = 777;
	std::cout << "b[1] = " << b[1] << ", d[1] = " << d[1] << std::endl;

	// Test 6: Out of bounds
	try {
		std::cout << b[100] << std::endl;
	} catch (std::exception &) {
		std::cout << "Exception thrown on out-of-bounds access" << std::endl;
	}

	return 0;
}
