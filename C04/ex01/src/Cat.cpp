#include "Cat.hpp"

void	Cat::setIdea(std::string idea, int index) {
	this->brain->setIdea(idea, index);
}

std::string	Cat::getIdea(int index) {
	return (this->brain->getIdea(index));
}

Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "A Cat has been constructed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	std::cout << "A Cat has been copy-constructed." << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "A Cat has been assigned." << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "A Cat has been destructed." << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
