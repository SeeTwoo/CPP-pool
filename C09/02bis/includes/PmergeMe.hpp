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
		static void	sortVector(std::vector &);
		static void	sortDeque(std::deque &);

		template <typename Iterator>
		static bool isSorted(Iterator begin, Iterator end);

		template <typename Sorter, typename Container>
		static long benchmarkSorting(Sorter sorter, Container& container);
}

# include "PMergeMe.tpp"

#endif
