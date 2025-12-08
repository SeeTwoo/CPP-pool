#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>
# include <iomanip>
# include <climits>
# include <cstdlib>

class PmergeMe {
    private:
        std::vector<int>    _vec;
        std::deque<int>     _deq;
        double              _timeVec;
        double              _timeDeq;

        // --- Vector Implementation ---
        void    _mergeInsertSortVec(std::vector<int>& arr);
        void    _insertInSortedVec(std::vector<int>& dest, int val);
        
        // --- Deque Implementation ---
        void    _mergeInsertSortDeq(std::deque<int>& arr);
        void    _insertInSortedDeq(std::deque<int>& dest, int val);

        // --- Shared Logic ---
        // Generates the order of indices for insertion based on Jacobsthal numbers
        std::vector<int> _generateInsertionOrder(size_t size);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& src);

        // Main runner
        void    sortAndMeasure(int argc, char **argv);
};

#endif
