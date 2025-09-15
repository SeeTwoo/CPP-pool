#include "FragTrap.hpp"
#include <iostream>

void	FragTrap::attack(const std::string &target) {
	if (hitPoints == 0) {
		std::cout << "FragTrap " << name << " is dead\n";
		return ;
	}
	if (energyPoints == 0) {
		std::cout << "FragTrap " << name << " has no energy left and cannot attack\n";
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage\n";
	energyPoints--;
}

void	FragTrap::guardGate() {
	std::cout << "FragTrap is now in gate keeper mode\n";
}

FragTrap::FragTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap name constructor called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Default destructor called\n";
}

FragTrap	&FragTrap::operator=(const FragTrap &other) {
	if (this == &other)
		return (*this);
	std::cout << "FragTrap Copy assignment operator called\n";
	this->name = other.name;
	this->hitPoints= other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}
