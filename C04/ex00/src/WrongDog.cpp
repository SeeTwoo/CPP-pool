#include "WrongDog.hpp"

WrongDog::WrongDog() {
	this->type = "WrongDog";
	std::cout << "A WrongDog has been constructed." << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : Animal(other) {
	std::cout << "A WrongDog has been copy-constructed." << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "A WrongDog has been assigned." << std::endl;
	return *this;
}

WrongDog::~WrongDog() {
	std::cout << "A WrongDog has been destructed." << std::endl;
}

void WrongDog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}
