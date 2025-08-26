#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << "creating object\n";
}

Zombie::~Zombie(void) {
	std::cout << "destroying object\n";
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name) {
	this->name = name;
}

Zombie	*newZombie(std::string name) {
	Zombie	*dest;

	dest = new Zombie(name);
	if (!dest)
		return (NULL);
	return (dest);
}

void	randomChump(std::string name) {
	Zombie	zombie((name));
	
	zombie.announce();
}
