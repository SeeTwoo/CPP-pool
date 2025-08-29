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

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this == &other)
		return (*this);
	std::cout << "Copy assignment operator called\n";
	this->Number = other.Number;
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return this->Number;
}
