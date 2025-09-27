#include <iostream>
#include "Animal.hpp"

void	Animal::makeSound() const {
	std::cout << "Generic ass animal sound\n";
}

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal copy constructor called\n";
}

Animal	&Animal::operator=(const Animal &other) {
	if (this == &other)
		return *this;
	type = other.type;
	std::cout << "Animal equal operator called\n";
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal default destructor called\n";
}
