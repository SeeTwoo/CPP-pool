/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   ClapTrap.cpp                                        :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>                +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

void	ClapTrap::attack(const std::string &target) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is dead\n";
		return ;
	}
	if (energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " has no energy left and cannot attack\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage !\n";
	energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is dead\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage\n";
	hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is dead\n";
		return ;
	}
	if (energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " has no energy left and cannot repair\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " repairs and regains " << amount << " point\n";
	energyPoints--;
	hitPoints++;
}

ClapTrap::ClapTrap() : name("Default ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "default constructor called\n";
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints),
	attackDamage(other.attackDamage) {
	std::cout << "Copy constructor called\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "Default destructor called\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	if (this == &other)
		return (*this);
	std::cout << "Copy assignment operator called\n";
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}
