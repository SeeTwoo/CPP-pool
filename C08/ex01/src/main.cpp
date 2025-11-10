#include <iostream>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Span sp(10000);

	std::srand(std::time(NULL));
	for (int i = 0; i < 10000; i++)
		sp.addNumber(std::rand());

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	// Demonstration of range insert
	Span sp2(5);
	std::vector<int> v;
	v.push_back(10);
	v.push_back(3);
	v.push_back(20);

	sp2.addRange(v.begin(), v.end());

	std::cout << "Shortest span (sp2): " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span (sp2): " << sp2.longestSpan() << std::endl;

	return 0;
}
