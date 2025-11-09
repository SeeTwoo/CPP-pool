#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

template<typename T>
void	printElement(T const &x)
{
	std::cout << x << std::endl;
}

template<typename T>
void	increment(T &x)
{
	++x;
}

#endif
