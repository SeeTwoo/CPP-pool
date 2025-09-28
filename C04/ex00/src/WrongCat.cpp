#include "WrongCat.hpp"

// Constructor sets the specific type for a WrongCat
WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "A WrongCat has been constructed." << std::endl;
}

// Copy Constructor
WrongCat::WrongCat(const WrongCat &other) : Animal(other) {
	std::cout << "A WrongCat has been copy-constructed." << std::endl;
}

// Assignment Operator
WrongCat& WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "A WrongCat has been assigned." << std::endl;
	return *this;
}

// Destructor
WrongCat::~WrongCat() {
	std::cout << "A WrongCat has been destructed." << std::endl;
}

// WrongCat's specific implementation of makeSound
void WrongCat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
