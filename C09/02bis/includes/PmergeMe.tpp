#include <ctime>

class PmergeMe;

template <typename Iterator>
bool PmergeMe::isSorted(Iterator begin, Iterator end)
{
    if (begin == end)
        return true;

    Iterator prev = begin;
    Iterator curr = begin;
    ++curr;

    while (curr != end) {
        if (*curr < *prev)
            return false;
        prev = curr;
        ++curr;
    }
    return true;
}

template <typename Sorter, typename Container>
long PmergeMe::benchmarkSorting(Sorter sorter, Container& container)
{
    clock_t start = clock();

    sorter(container);

    clock_t end = clock();

    return static_cast<long>(
        (end - start) * 1000000 / CLOCKS_PER_SEC
    );
}

