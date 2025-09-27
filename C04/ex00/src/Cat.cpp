#include <iostream>
#include "Cat.hpp"

void	Cat::makeSound() {
	std::cout << "Meow\n";
}

Cat::Cat() {
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called\n";
}

Cat	&Cat::operator=(const Cat &other) {
	if (this == &other)
		return *this;
	type = other.type;
	std::cout << "Cat equal operator called\n";
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called\n";
}
