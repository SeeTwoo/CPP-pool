#include "Animal.hpp"

Animal::Animal() : type("Generic Animal") {
	std::cout << "An Animal has been constructed." << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
	std::cout << "An Animal has been copy-constructed." << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "An Animal has been assigned." << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "An Animal has been destructed." << std::endl;
}

void Animal::makeSound() const {
	std::cout << " * Unintelligible animal sounds * " << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}