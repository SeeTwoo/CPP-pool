#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "A WrongCat has been constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "A WrongCat has been copy-constructed." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "A WrongCat has been assigned." << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "A WrongCat has been destructed." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
