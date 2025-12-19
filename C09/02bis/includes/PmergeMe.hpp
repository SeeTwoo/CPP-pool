#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

class PmergeMe {
	private :
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe	&operator=(const PmergeMe &);
		~PmergeMe();
	public :
		static void	sortVector(std::vector<int> &);
		static void	sortDeque(std::deque<int> &);

		template <typename Iterator>
		static bool isSorted(Iterator begin, Iterator end);

		template <typename Sorter, typename Container>
		static long benchmarkSorting(Sorter sorter, Container& container);
};

# include "PmergeMe.tpp"

#endif
