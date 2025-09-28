#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Generic WrongAnimal") {
	std::cout << "An WrongAnimal has been constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
	std::cout << "An WrongAnimal has been copy-constructed." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "An WrongAnimal has been assigned." << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "An WrongAnimal has been destructed." << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << " * Unintelligible animal sounds * " << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
