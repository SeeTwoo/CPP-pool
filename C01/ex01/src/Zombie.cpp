#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	std::cout << "default constructor called\n";
}

Zombie::~Zombie() {
	std::cout << "default destructor called\n";
}

void	Zombie::announce() {
	std::cout << name << "\n";
}

void	Zombie::setName(std::string newName) {
	this->name = newName;
}
