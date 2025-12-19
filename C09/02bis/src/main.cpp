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
	std::deque<int>		deq;

	fillContainer(vec, ac, av);
	fillContainer(deq, ac, av);
	PmergeMe::sort(vec);
	PmergeMe::sort(deq);
	if (PmergeMe::isSorted(vec.begin(), vec.end()))
		std::cout << "vector properly sorted !\n";
	else
		std::cout << "\e[31mvector not sorted !\e[0m\n";
	if (PmergeMe::isSorted(deq.begin(), deq.end()))
		std::cout << "deque properly sorted !\n";
	else
		std::cout << "\e[31mdeque not sorted !\e[0m\n";
	return 0;
}
