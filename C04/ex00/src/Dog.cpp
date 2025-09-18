#include <iostream>
#include "Dog.hpp"

void	makeSound() {
	std::cout << "Woof\n";
}

Dog::Dog() {
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &other) : type(other.type) {
	std::cout << "Dog copy constructor called\n";
}

Dog	&operator=(const Dog &other) {
	if (this == &other)
		return *this;
	type = other.type;
	std::cout << "Dog equal operator called\n";
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called\n";
}
