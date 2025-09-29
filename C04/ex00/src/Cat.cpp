#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "A Cat has been constructed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "A Cat has been copy-constructed." << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "A Cat has been assigned." << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "A Cat has been destructed." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
