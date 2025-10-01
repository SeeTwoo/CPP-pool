#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "A Dog has been constructed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	std::cout << "A Dog has been copy-constructed." << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "A Dog has been assigned." << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "A Dog has been destructed." << std::endl;
	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}
