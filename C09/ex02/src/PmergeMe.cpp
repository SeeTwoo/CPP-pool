#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVec(0), _timeDeq(0) {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }
PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
    if (this != &src) {
        _vec = src._vec;
        _deq = src._deq;
        _timeVec = src._timeVec;
        _timeDeq = src._timeDeq;
    }
    return *this;
}

std::vector<int> PmergeMe::_generateInsertionOrder(size_t size) {
    std::vector<int> pattern;

    if (size == 0)
		return pattern;

    size_t jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
    size_t last_val = 1;
    
    for (size_t i = 1; i < sizeof(jacobsthal)/sizeof(size_t); ++i) {
        size_t next_limit = jacobsthal[i];
        
        if (next_limit > size)
            next_limit = size;

        for (size_t j = next_limit; j > last_val; --j)
            pattern.push_back(j - 1);

        last_val = next_limit;
        if (last_val >= size) break;
    }
    return pattern;
}

void PmergeMe::_insertInSortedVec(std::vector<int>& dest, int val) {
    std::vector<int>::iterator it = std::lower_bound(dest.begin(), dest.end(), val);
    dest.insert(it, val);
}

void PmergeMe::_mergeInsertSortVec(std::vector<int>& arr) {
    size_t n = arr.size();
    if (n < 2)
		return;

    bool hasStraggler = (n % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    _mergeInsertSortVec(mainChain);

    std::vector<int> pending;
    
    std::vector<bool> usedPair(pairs.size(), false);
    
    std::vector<int> result = mainChain;
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (!usedPair[i] && pairs[i].first == result[0]) {
            result.insert(result.begin(), pairs[i].second);
            usedPair[i] = true;
            break;
        }
    }

    for (size_t k = 1; k < result.size(); ++k) {
        int winner = result[k];
        for (size_t i = 0; i < pairs.size(); ++i) {
            if (!usedPair[i] && pairs[i].first == winner) {
                pending.push_back(pairs[i].second);
                usedPair[i] = true;
                break;
            }
        }
    }

    std::vector<int> order = _generateInsertionOrder(pending.size());

    for (size_t i = 0; i < order.size(); ++i) {
        int idx = order[i];
        int valToInsert = pending[idx];
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), valToInsert);
        result.insert(pos, valToInsert);
    }

    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }

    arr = result;
}

void PmergeMe::_insertInSortedDeq(std::deque<int>& dest, int val) {
    std::deque<int>::iterator it = std::lower_bound(dest.begin(), dest.end(), val);
    dest.insert(it, val);
}

void PmergeMe::_mergeInsertSortDeq(std::deque<int>& arr) {
    size_t n = arr.size();
    if (n < 2)
		return;

    bool hasStraggler = (n % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    _mergeInsertSortDeq(mainChain);

    std::deque<int> pending;
    std::deque<bool> usedPair(pairs.size(), false);
    
    std::deque<int> result = mainChain;
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (!usedPair[i] && pairs[i].first == result[0]) {
            result.push_front(pairs[i].second);
            usedPair[i] = true;
            break;
        }
    }

    for (size_t k = 1; k < result.size(); ++k) {
        int winner = result[k];
        for (size_t i = 0; i < pairs.size(); ++i) {
            if (!usedPair[i] && pairs[i].first == winner) {
                pending.push_back(pairs[i].second);
                usedPair[i] = true;
                break;
            }
        }
    }

    std::vector<int> order = _generateInsertionOrder(pending.size());

    for (size_t i = 0; i < order.size(); ++i) {
        int idx = order[i];
        int valToInsert = pending[idx];
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), valToInsert);
        result.insert(pos, valToInsert);
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }

    arr = result;
}

void PmergeMe::sortAndMeasure(int argc, char **argv) {
    _vec.clear();
    _deq.clear();

    for (int i = 1; i < argc; ++i) {
        char *endptr;
        long val = std::strtol(argv[i], &endptr, 10);
        
        if (*endptr != '\0' || val < 0 || val > INT_MAX) {
            std::cerr << "Error" << std::endl;
            return;
        }
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }

    if (_vec.empty())
        return;

    std::cout << "Before: ";
    size_t limit = (_vec.size() > 5) ? 5 : _vec.size();
    for (size_t i = 0; i < limit; ++i) std::cout << _vec[i] << " ";
    if (_vec.size() > 5) std::cout << "[...]";
    std::cout << std::endl;

    std::clock_t startVec = std::clock();
    _mergeInsertSortVec(_vec);
    std::clock_t endVec = std::clock();
    _timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    std::clock_t startDeq = std::clock();
    _mergeInsertSortDeq(_deq);
    std::clock_t endDeq = std::clock();
    _timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After:  ";
    for (size_t i = 0; i < limit; ++i) std::cout << _vec[i] << " ";
    if (_vec.size() > 5) std::cout << "[...]";
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << _timeVec << " us" << std::endl;
              
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << _timeDeq << " us" << std::endl;
}
