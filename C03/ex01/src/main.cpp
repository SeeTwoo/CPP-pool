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

int	main() {
	ClapTrap	basic("Basic");
	ScavTrap	guardian("Guardian");

	basic.attack("Training dummy");
	guardian.attack("Training dummy");
	guardian.takeDamage(30);
    guardian.beRepaired(20);

    std::cout << "\nGuard Gate Ability" << std::endl;
    guardian.guardGate();

    std::cout << "\nEnergy Drain Test" << std::endl;
    for (int i = 0; i < 48; i++)
        guardian.attack("Dummy target");
    guardian.attack("Dummy target");
    guardian.beRepaired(10);

    std::cout << "\nDeath Test" << std::endl;
    guardian.takeDamage(200);
    guardian.attack("Basic");
    guardian.beRepaired(10);
    guardian.guardGate(); 
	return 0;
}
