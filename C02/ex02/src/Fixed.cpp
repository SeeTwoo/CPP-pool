/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   Fixed.cpp                                           :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>                +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : Number(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) : Number(other.Number) {
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Default destructor called\n";
}

Fixed::Fixed(const int param) : Number(param * (1L << BinaryPointPosition)) {
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float param) : Number(param * (1L << BinaryPointPosition)) {
	std::cout << "Float constructor called\n";
}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this == &other)
		return (*this);
	std::cout << "Copy assignment operator called\n";
	this->Number = other.Number;
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed &Number) {
	os << (float)Number.toFloat();
	return os;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return this->Number;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(Number) / (1 << BinaryPointPosition);
}

int	Fixed::toInt(void) const {
	return (Number / (1L << BinaryPointPosition));
}

//operator overloading

bool	Fixed::operator>=(const Fixed &other) const {
	return this->Number >= other.Number;
}

bool	Fixed::operator<=(const Fixed &other) const {
	return this->Number <= other.Number;
}

bool	Fixed::operator==(const Fixed &other) const {
	return this->Number == other.Number;
}

bool	Fixed::operator!=(const Fixed &other) const {
	return this->Number != other.Number;
}

bool	Fixed::operator>(const Fixed &other) const {
	return this->Number > other.Number;
}

bool	Fixed::operator<(const Fixed &other) const {
	return this->Number > other.Number;
}

Fixed	&Fixed::operator++() {
	this->Number++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	this->Number++;
	return tmp;
}

Fixed	&Fixed::operator--() {
	this->Number--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	this->Number--;
	return tmp;
}
