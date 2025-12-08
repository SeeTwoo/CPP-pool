#include "PmergeMe.hpp"

// -----------------------------------------------------------------------------
// Canonical Form
// -----------------------------------------------------------------------------
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

// -----------------------------------------------------------------------------
// Helper: Jacobsthal Insertion Order
// Generates indices like: 3, 2, 5, 4, 11, 10, 9, 8, 7, 6...
// -----------------------------------------------------------------------------
std::vector<int> PmergeMe::_generateInsertionOrder(size_t size) {
    std::vector<int> pattern;
    if (size == 0) return pattern;

    // Standard Jacobsthal numbers: 0, 1, 1, 3, 5, 11, 21, 43...
    // We use them to determine the end of the next batch.
    // Starting Jacobsthal numbers relevant for insertion groups (skipping first two 1s)
    size_t jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
    
    // We assume index 0 is already handled (it goes with the first winner).
    // So we are scheduling indices 1 to size-1.
    
    size_t last_val = 1; // The last index we fully covered
    
    for (size_t i = 1; i < sizeof(jacobsthal)/sizeof(size_t); ++i) {
        size_t next_limit = jacobsthal[i];
        
        if (next_limit > size)
            next_limit = size;

        // Push indices in decreasing order from next_limit down to last_val + 1
        for (size_t j = next_limit; j > last_val; --j) {
            // We push j-1 because we are working with 0-based index logic 
            // relative to the 'pending' container.
            pattern.push_back(j - 1);
        }

        last_val = next_limit;
        if (last_val >= size) break;
    }
    return pattern;
}

// -----------------------------------------------------------------------------
// VECTOR IMPLEMENTATION
// -----------------------------------------------------------------------------
void PmergeMe::_insertInSortedVec(std::vector<int>& dest, int val) {
    // std::lower_bound uses binary search
    std::vector<int>::iterator it = std::lower_bound(dest.begin(), dest.end(), val);
    dest.insert(it, val);
}

void PmergeMe::_mergeInsertSortVec(std::vector<int>& arr) {
    size_t n = arr.size();
    if (n < 2) return;

    // 1. Handle Straggler
    bool hasStraggler = (n % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    // 2. Create Pairs (Winner, Loser)
    // We want the 'main chain' to contain the larger elements.
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1])); // (Large, Small)
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i])); // (Large, Small)
    }

    // 3. Recursively sort the main chain (the large elements)
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    _mergeInsertSortVec(mainChain);

    // 4. Create Pending Chain and Re-map
    // mainChain is now sorted. We must place the losers (pending) corresponding 
    // to the sorted winners.
    std::vector<int> pending;
    
    // NOTE: In a pure optimization, we'd avoid this O(N) search loop by tracking indices,
    // but for the Simplified 42 requirement, this ensures correct pairing with duplicates.
    // We use a temporary list of pairs to mark used ones to handle duplicates correctly.
    std::vector<bool> usedPair(pairs.size(), false);
    
    // We also need to build the initial 'S' chain which includes the first loser
    // The first loser (paired with mainChain[0]) is guaranteed to be smaller than mainChain[0],
    // and mainChain[0] is the smallest of winners. So first loser is the new global min.
    
    std::vector<int> result = mainChain;
    
    // Find the loser associated with result[0] (the smallest winner)
    // and insert it at the very beginning.
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (!usedPair[i] && pairs[i].first == result[0]) {
            result.insert(result.begin(), pairs[i].second);
            usedPair[i] = true;
            break;
        }
    }

    // Now populate 'pending' with the rest of the losers in the order 
    // corresponding to the current 'mainChain' (result) order (excluding the one we just inserted).
    // Note: result has size N/2 + 1 currently. result[1] is the first original winner.
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

    // 5. Insert Pending elements using Jacobsthal order
    std::vector<int> order = _generateInsertionOrder(pending.size());

    for (size_t i = 0; i < order.size(); ++i) {
        int idx = order[i];
        int valToInsert = pending[idx];

        // OPTIMIZATION:
        // We only need to binary search in 'result' up to the position of its partner.
        // However, since 'result' grows, finding the partner index dynamically is complex.
        // But we know that the partner of pending[idx] was originally at mainChain[idx].
        // The simplified version often just binary searches the whole valid range.
        
        // A standard simplified approach: Search the entire list constructed SO FAR.
        // (Wait: Ford-Johnson optimization limits search range to partner's index. 
        //  Here, we simply binary search the current result vector.)
        
        // Find position and insert
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), valToInsert);
        result.insert(pos, valToInsert);
    }

    // 6. Insert Straggler (if any)
    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }

    arr = result;
}

// -----------------------------------------------------------------------------
// DEQUE IMPLEMENTATION (Exact copy logic adapted for Deque)
// -----------------------------------------------------------------------------
void PmergeMe::_insertInSortedDeq(std::deque<int>& dest, int val) {
    std::deque<int>::iterator it = std::lower_bound(dest.begin(), dest.end(), val);
    dest.insert(it, val);
}

void PmergeMe::_mergeInsertSortDeq(std::deque<int>& arr) {
    size_t n = arr.size();
    if (n < 2) return;

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

// -----------------------------------------------------------------------------
// MAIN PUBLIC METHOD
// -----------------------------------------------------------------------------
void PmergeMe::sortAndMeasure(int argc, char **argv) {
    _vec.clear();
    _deq.clear();

    // 1. Parsing
    for (int i = 1; i < argc; ++i) {
        char *endptr;
        long val = std::strtol(argv[i], &endptr, 10);
        
        if (*endptr != '\0' || val < 0 || val > INT_MAX) {
            std::cerr << "Error" << std::endl;
            return;
        }
        // Assuming strict positive as per subject "positive integer sequence" (usually > 0 or >= 0)
        // Subject example "3 5 9 7 4" implies positive. "-1" is error.
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }

    if (_vec.empty())
        return;

    // Display Before
    std::cout << "Before: ";
    size_t limit = (_vec.size() > 5) ? 5 : _vec.size();
    for (size_t i = 0; i < limit; ++i) std::cout << _vec[i] << " ";
    if (_vec.size() > 5) std::cout << "[...]";
    std::cout << std::endl;

    // 2. Process Vector
    std::clock_t startVec = std::clock();
    _mergeInsertSortVec(_vec);
    std::clock_t endVec = std::clock();
    _timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000; // in us

    // 3. Process Deque
    std::clock_t startDeq = std::clock();
    _mergeInsertSortDeq(_deq);
    std::clock_t endDeq = std::clock();
    _timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000; // in us

    // Display After
    std::cout << "After:  ";
    for (size_t i = 0; i < limit; ++i) std::cout << _vec[i] << " ";
    if (_vec.size() > 5) std::cout << "[...]";
    std::cout << std::endl;

    // Display Times
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << _timeVec << " us" << std::endl;
              
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << _timeDeq << " us" << std::endl;
}
