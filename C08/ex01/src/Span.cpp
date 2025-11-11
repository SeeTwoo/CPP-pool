#include "Span.hpp"

void Span::addNumber(int value)
{
	if (_data.size() >= _maxSize)
		throw std::runtime_error("Span: cannot add more numbers, span is full.");
	_data.push_back(value);
}

long Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("Span: not enough numbers to find a span.");

	std::vector<int> copy = _data;
	std::sort(copy.begin(), copy.end());

	long minSpan = static_cast<long>(copy[1]) - static_cast<long>(copy[0]);
	for (size_t i = 1; i < copy.size() - 1; ++i)
	{
		long span = static_cast<long>(copy[i + 1]) - static_cast<long>(copy[i]);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

long Span::longestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("Span: not enough numbers to find a span.");

	int minVal = *std::min_element(_data.begin(), _data.end());
	int maxVal = *std::max_element(_data.begin(), _data.end());

	return static_cast<long>(maxVal) - static_cast<long>(minVal);
}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _data(other._data) {}

Span &Span::operator=(const Span &other) {
	if (this == &other)
		return *this;
	_maxSize = other._maxSize;
	_data = other._data;
	return *this;
}

Span::~Span() {}
