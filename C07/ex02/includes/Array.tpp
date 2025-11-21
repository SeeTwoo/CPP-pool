#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <new>

template <typename T>
Array<T>::Array() : m_data(NULL), m_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : m_data(NULL), m_size(n) {
	if (n == 0)
		return;
	m_data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other) : m_data(NULL), m_size(other.m_size) {
	if (m_size == 0)
		return;
	m_data = new T[m_size];
	for (unsigned int i = 0; i < m_size; ++i)
		m_data[i] = other.m_data[i];
}

template <typename T>
Array<T>::~Array() {delete[] m_data;}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this == &other)
		return *this;

	delete[] m_data;

	m_size = other.m_size;
	if (m_size == 0) {
		m_data = NULL;
		return *this;
	}

	m_data = new T[m_size];
	for (unsigned int i = 0; i < m_size; ++i)
		m_data[i] = other.m_data[i];

	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= m_size)
		throw std::exception();
	return m_data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= m_size)
		throw std::exception();
	return m_data[index];
}

template <typename T>
unsigned int Array<T>::size() const {return m_size;}

#endif
