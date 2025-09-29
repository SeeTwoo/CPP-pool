#include "Cat.hpp"

// Constructor sets the specific type for a Cat
Cat::Cat() {
	this->type = "Cat";
	std::cout << "A Cat has been constructed." << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "A Cat has been copy-constructed." << std::endl;
}

// Assignment Operator
Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "A Cat has been assigned." << std::endl;
	return *this;
}

// Destructor
Cat::~Cat() {
	std::cout << "A Cat has been destructed." << std::endl;
}

// Cat's specific implementation of makeSound
void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
