#include "PmergeMe.hpp"

static void initStraggler(std::vector<int>& v, bool& hasStraggler, int& straggler)
{
    if (v.size() % 2 == 0)
        return;

    hasStraggler = true;
    straggler = v.front();
    v.erase(v.begin());
}


void	PmergeMe::sortVector(std::vector &v) {
	std::vector	toSort(v);
	bool		hasStraggler = false;
	int			straggler;

	initStraggler(toSort, hasStragler, straggler);
}
