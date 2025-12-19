#include "PmergeMe.hpp"
#include <iostream>

#include <cstdlib>
#include <stdexcept>

template <typename Container>
void fillContainer(Container& c, int ac, char** av)
{
    for (int i = 1; i < ac; ++i)
    {
        char* end = NULL;
        long value = std::strtol(av[i], &end, 10);

        if (*end != '\0')
            throw std::invalid_argument("Non-numeric argument");

        c.push_back(static_cast<typename Container::value_type>(value));
    }
}

int	main(int ac, char **av) {
	std::vector<int>	vec;

	fillContainer(vec, ac, av);
	PmergeMe::sortVector(vec);
	if (PmergeMe::isSorted(vec.begin(), vec.end()))
		std::cout << "properly sorted !\n";
	else
		std::cout << "not sorted !\n";
	return 0;
}
