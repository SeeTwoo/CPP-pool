#include "PmergeMe.hpp"

#include <iostream>
void	PmergeMe::sortDeque(std::deque<int> &d) {
	(void)d;
	std::cout << "ya rien frerot" << std::endl;
}

int binarySearch(const std::vector<int>& chain, int target, int right) {
    int left = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (chain[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

void PmergeMe::sortVector(std::vector<int> &v) {
    if (v.size() < 2) return;

    bool odd = v.size() % 2 != 0;
    int strag = 0;
    if (odd) {
        strag = v.back();
        v.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < v.size(); i += 2) {
        if (v[i] < v[i + 1])
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
        else
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
    }

    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].first);

    sortVector(larger);

    std::vector<int> pending;
    std::vector<std::pair<int, int> > tempPairs = pairs;
    for (size_t i = 0; i < larger.size(); ++i) {
        for (size_t j = 0; j < tempPairs.size(); ++j) {
            if (larger[i] == tempPairs[j].first) {
                pending.push_back(tempPairs[j].second);
                tempPairs.erase(tempPairs.begin() + j);
                break;
            }
        }
    }

    std::vector<int> mainChain;
    mainChain.push_back(pending[0]);
    for (size_t i = 0; i < larger.size(); ++i)
        mainChain.push_back(larger[i]);

    std::vector<int> jacob;
    jacob.push_back(1);
    jacob.push_back(3);
    while (jacob.back() < (int)pending.size())
        jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);

    for (size_t k = 1; k < jacob.size(); ++k) {
        int end = (jacob[k] < (int)pending.size()) ? jacob[k] : (int)pending.size();
        int start = jacob[k - 1];
        for (int i = end - 1; i >= start; --i) {
            int limit = 0;
            while (limit < (int)mainChain.size() && mainChain[limit] != larger[i])
                limit++;
            mainChain.insert(mainChain.begin() + binarySearch(mainChain, pending[i], limit - 1), pending[i]);
        }
    }

    if (odd)
        mainChain.insert(mainChain.begin() + binarySearch(mainChain, strag, (int)mainChain.size() - 1), strag);

    v = mainChain;
}