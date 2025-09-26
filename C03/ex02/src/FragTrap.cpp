#include "FragTrap.hpp"
#include <iostream>

void	FragTrap::highFivesGuys() {
	if (hitPoints <= 0) {
		std::cout << "FragTrap " << name << " is dead\n";
		return ;
	}
	std::cout << "let's high five guys !\n";
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
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Default destructor called\n";
}

FragTrap	&FragTrap::operator=(const FragTrap &other) {
	if (this == &other)
		return (*this);
	std::cout << "FragTrap Copy assignment operator called\n";
	ClapTrap::operator=(other);
	return (*this);
}
