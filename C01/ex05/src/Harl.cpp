/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   Harl.cpp                                            :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>                +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-chese-triple-pickle-special-ketchup burder. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believ adding extra bacon costs more money. You didn't put enough bacon in my burger! if you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have seme extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void	(Harl::*complainers[4])(void) = {
		&Harl::debug,
		&Harl::info, 
		&Harl::warning, 
		&Harl::error
	};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*complainers[i])();
			return ;
		}
	}
	std::cout << "I cannot even think of something to say... you charging me when I am just asking for MORE BACON is outrageous\n";
}
