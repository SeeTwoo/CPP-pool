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

int	main() {
	ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    std::cout << "\nBasic Attack Test" << std::endl;
    a.attack("Bravo");
    b.takeDamage(0);

    std::cout << "\nTake Damage Test" << std::endl;
    b.takeDamage(3);
    b.takeDamage(8);

    std::cout << "\nDead ClapTrap Cannot Act" << std::endl;
    b.attack("Alpha");
    b.beRepaired(5);

    std::cout << "\nRepair Test" << std::endl;
    a.takeDamage(5);
    a.beRepaired(3);
    a.beRepaired(10);

    std::cout << "\nEnergy Depletion Test" << std::endl;
    for (int i = 0; i < 8; i++)
        a.attack("Training dummy");
    a.attack("Training dummy");
    a.beRepaired(1);

    std::cout << "\nDestructor Test" << std::endl;
    return 0;
}
