#include "Dog.hpp"

// Constructor sets the specific type for a Dog
Dog::Dog() {
	this->type = "Dog";
	std::cout << "A Dog has been constructed." << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "A Dog has been copy-constructed." << std::endl;
}

// Assignment Operator
Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "A Dog has been assigned." << std::endl;
	return *this;
}

// Destructor
Dog::~Dog() {
	std::cout << "A Dog has been destructed." << std::endl;
}

// Dog's specific implementation of makeSound
void Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}
