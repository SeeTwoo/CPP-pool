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
		template <typename Container>
		static void	sort(Container &);

		template <typename Iterator>
		static bool isSorted(Iterator begin, Iterator end);

		template <typename Sorter, typename Container>
		static long benchmarkSorting(Sorter sorter, Container& container);
};

# include "PmergeMe.tpp"

#endif
