#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::attack(void) {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
	else
		std::cout << name << " has no weapon to attack with" << "\n";
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
