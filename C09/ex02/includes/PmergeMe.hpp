#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		// Vector-based algorithm
		void	mergeInsertSortVec(std::vector<int> &c);
		void	createPairsVec(std::vector<std::pair<int,int> > &pairs, const std::vector<int> &input);
		void	buildMainChainVec(std::vector<int> &mainChain, const std::vector<std::pair<int,int> > &pairs);
		void	insertPendingVec(std::vector<int> &mainChain, const std::vector<std::pair<int,int> > &pairs);

		// Deque-based algorithm
		void	mergeInsertSortDeq(std::deque<int> &c);
		void	createPairsDeq(std::deque<std::pair<int,int> > &pairs, const std::deque<int> &input);
		void	buildMainChainDeq(std::deque<int> &mainChain, const std::deque<std::pair<int,int> > &pairs);
		void	insertPendingDeq(std::deque<int> &mainChain, const std::deque<std::pair<int,int> > &pairs);

		// Jacobsthal utilities
		std::vector<size_t>	makeJacobsthal(size_t n) const;

		// Binary insertion helpers
		void	binaryInsertVec(std::vector<int> &c, int value);
		void	binaryInsertDeq(std::deque<int> &c, int value);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	load(int argc, char **argv);

		const std::vector<int>	&getVec() const;
		const std::deque<int>	&getDeq() const;

		void	sortVec();
		void	sortDeq();
};

#endif

