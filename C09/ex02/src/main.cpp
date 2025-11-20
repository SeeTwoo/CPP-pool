#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdexcept>

#include "PmergeMe.hpp"

static void printVec(const std::vector<int> &v) {
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error\n";
		return 1;
	}

	PmergeMe sorter;

	try {
		sorter.load(argc, argv);
	} catch (...) {
		std::cerr << "Error\n";
		return 1;
	}

	std::cout << "Before: ";
	printVec(sorter.getVec());
	std::cout << "\n";

	clock_t startVec = clock();
	sorter.sortVec();
	clock_t endVec = clock();

	std::cout << "After: ";
	printVec(sorter.getVec());
	std::cout << "\n";

	double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

	clock_t startDeq = clock();
	sorter.sortDeq();
	clock_t endDeq = clock();

	double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of "
			  << sorter.getVec().size()
			  << " elements with std::vector : "
			  << timeVec << " us\n";

	std::cout << "Time to process a range of "
			  << sorter.getVec().size()
			  << " elements with std::deque : "
			  << timeDeq << " us\n";

	return 0;
}
