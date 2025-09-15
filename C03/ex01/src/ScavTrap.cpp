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

ScavTrap::ScavTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap name constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Default destructor called\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other) {
	if (this == &other)
		return (*this);
	std::cout << "ScavTrap Copy assignment operator called\n";
	this->name = other.name;
	this->hitPoints= other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}
