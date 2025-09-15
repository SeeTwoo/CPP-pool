#include "ScavTrap.hpp"
#include <iostream>

void	ScavTrap::attack(const std::string &target) {
	if (hitPoints == 0) {
		std::cout << "ScavTrap " << name << " is dead\n";
		return ;
	}
	if (energyPoints == 0) {
		std::cout << "ScavTrap " << name << " has no energy left and cannot attack\n";
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage\n";
	energyPoints--;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in gate keeper mode\n";
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap name constructor called\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Default destructor called\n";
}
