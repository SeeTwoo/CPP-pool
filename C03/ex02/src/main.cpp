/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   main.cpp                                            :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>                +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	ClapTrap basic("Basic");
	ScavTrap guard("Guardian");
	FragTrap fraggy("Fraggy");

	std::cout << "\nStat Difference Test" << std::endl;
	// ClapTrap: HP=10, EP=10, AD=0
	// ScavTrap: HP=100, EP=50, AD=20
	// FragTrap: HP=100, EP=100, AD=30
	basic.attack("training dummy");
	guard.attack("training dummy");
	fraggy.attack("training dummy");

	std::cout << "\nDamage & Repair Test" << std::endl;
	fraggy.takeDamage(40);
	fraggy.beRepaired(25);

	std::cout << "\nSpecial Ability Test" << std::endl;
	guard.guardGate();
	fraggy.highFivesGuys();

	std::cout << "\nEnergy Drain Test (FragTrap)" << std::endl;
	for (int i = 0; i < 98; i++)
		fraggy.attack("training dummy");
	fraggy.attack("training dummy");
	fraggy.beRepaired(10);

	std::cout << "\nDeath Test (FragTrap)" << std::endl;
	fraggy.takeDamage(200);
	fraggy.attack("training dummy");
	fraggy.beRepaired(50);
	fraggy.highFivesGuys();
	return 0;
}
