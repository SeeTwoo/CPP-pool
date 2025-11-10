#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int value);

	template<typename It>
	void addRange(It begin, It end)
	{
		if (static_cast<unsigned int>(std::distance(begin, end)) + _data.size() > _maxSize)
			throw std::runtime_error("Span: adding range exceeds maximum size.");
		_data.insert(_data.end(), begin, end);
	}

	long shortestSpan() const;
	long longestSpan() const;

private:
	unsigned int _maxSize;
	std::vector<int> _data;
};

#endif
