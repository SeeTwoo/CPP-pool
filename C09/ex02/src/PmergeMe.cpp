#include <stdexcept>
#include <cstdlib>
#include <climits>

#include "PmergeMe.hpp"

// Jacobsthal sequence

std::vector<size_t> PmergeMe::makeJacobsthal(size_t n) const {
	std::vector<size_t> seq;
	if (n == 0)
		return seq;

	seq.push_back(1);
	if (n == 1)
		return seq;

	seq.push_back(3);

	while (seq.back() < n) {
		size_t sz = seq.size();
		size_t next = seq[sz - 1] + 2 * seq[sz - 2];
		if (next > n)
			break;
		seq.push_back(next);
	}
	return seq;
}

// Load integers

void PmergeMe::load(int argc, char **argv) {
	_vec.clear();
	_deq.clear();

	for (int i = 1; i < argc; ++i) {
		char *end = 0;
		long v = std::strtol(argv[i], &end, 10);
		if (*end != '\0' || v <= 0 || v > INT_MAX)
			throw std::runtime_error("Error");

		_vec.push_back(static_cast<int>(v));
		_deq.push_back(static_cast<int>(v));
	}
}

const std::vector<int> &PmergeMe::getVec() const { return _vec; }
const std::deque<int> &PmergeMe::getDeq() const { return _deq; }

// Binary insert helpers

void PmergeMe::binaryInsertVec(std::vector<int> &c, int value) {
	size_t left = 0;
	size_t right = c.size();

	while (left < right) {
		size_t mid = (left + right) / 2;
		if (c[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	c.insert(c.begin() + left, value);
}

void PmergeMe::binaryInsertDeq(std::deque<int> &c, int value) {
	size_t left = 0;
	size_t right = c.size();

	while (left < right) {
		size_t mid = (left + right) / 2;
		if (c[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	c.insert(c.begin() + left, value);
}

// VECTOR: Create pairs

void PmergeMe::createPairsVec(std::vector<std::pair<int,int> > &pairs, const std::vector<int> &input) {
	pairs.clear();
	size_t i = 0;

	while (i + 1 < input.size()) {
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
		i += 2;
	}
	if (i < input.size())
		pairs.push_back(std::make_pair(input[i], input[i]));
}

// VECTOR: Build main chain from larger elements

void PmergeMe::buildMainChainVec(std::vector<int> &mainChain, const std::vector<std::pair<int,int> > &pairs) {
	mainChain.clear();
	for (size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].second);

	for (size_t i = 1; i < mainChain.size(); ++i) {
		int key = mainChain[i];
		int j = i - 1;
		while (j >= 0 && mainChain[j] > key) {
			mainChain[j + 1] = mainChain[j];
			j--;
		}
		mainChain[j + 1] = key;
	}
}

// VECTOR: Insert smaller elements via Jacobsthal order

void PmergeMe::insertPendingVec(std::vector<int> &mainChain, const std::vector<std::pair<int,int> > &pairs) {
	std::vector<int> pending;
	for (size_t i = 0; i < pairs.size(); ++i)
		pending.push_back(pairs[i].first);

	std::vector<size_t> jac = makeJacobsthal(pending.size());
	size_t inserted = 0;

	for (size_t j = 0; j < jac.size(); ++j) {
		size_t batchSize = jac[j];
		if (batchSize > pending.size())
			batchSize = pending.size();

		while (inserted < batchSize) {
			binaryInsertVec(mainChain, pending[inserted]);
			inserted++;
		}
	}

	while (inserted < pending.size()) {
		binaryInsertVec(mainChain, pending[inserted]);
		inserted++;
	}
}

// VECTOR version

void PmergeMe::mergeInsertSortVec(std::vector<int> &c) {
	if (c.size() <= 1)
		return;

	std::vector<std::pair<int,int> > pairs;
	createPairsVec(pairs, c);

	std::vector<int> mainChain;
	buildMainChainVec(mainChain, pairs);
	insertPendingVec(mainChain, pairs);

	c = mainChain;
}

void PmergeMe::sortVec() {
	mergeInsertSortVec(_vec);
}

// DEQUE version

void PmergeMe::createPairsDeq(std::deque<std::pair<int,int> > &pairs, const std::deque<int> &input) {
	pairs.clear();
	size_t i = 0;

	while (i + 1 < input.size()) {
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
		i += 2;
	}

	if (i < input.size())
		pairs.push_back(std::make_pair(input[i], input[i]));
}

void PmergeMe::buildMainChainDeq(std::deque<int> &mainChain, const std::deque<std::pair<int,int> > &pairs) {
	mainChain.clear();
	for (size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].second);

	for (size_t i = 1; i < mainChain.size(); ++i) {
		int key = mainChain[i];
		int j = i - 1;
		while (j >= 0 && mainChain[j] > key) {
			mainChain[j + 1] = mainChain[j];
			j--;
		}
		mainChain[j + 1] = key;
	}
}

void PmergeMe::insertPendingDeq(std::deque<int> &mainChain, const std::deque<std::pair<int,int> > &pairs) {
	std::deque<int> pending;
	for (size_t i = 0; i < pairs.size(); ++i)
		pending.push_back(pairs[i].first);

	std::vector<size_t> jac = makeJacobsthal(pending.size());
	size_t inserted = 0;

	for (size_t j = 0; j < jac.size(); ++j) {
		size_t batchSize = jac[j];
		if (batchSize > pending.size())
			batchSize = pending.size();
		while (inserted < batchSize) {
			binaryInsertDeq(mainChain, pending[inserted]);
			inserted++;
		}
	}

	while (inserted < pending.size()) {
		binaryInsertDeq(mainChain, pending[inserted]);
		inserted++;
	}
}

void PmergeMe::mergeInsertSortDeq(std::deque<int> &c) {
	if (c.size() <= 1)
		return;

	std::deque<std::pair<int,int> > pairs;
	createPairsDeq(pairs, c);

	std::deque<int> mainChain;
	buildMainChainDeq(mainChain, pairs);
	insertPendingDeq(mainChain, pairs);

	c = mainChain;
}

void PmergeMe::sortDeq() {
	mergeInsertSortDeq(_deq);
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}
