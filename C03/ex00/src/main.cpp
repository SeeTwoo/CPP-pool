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

#include "ClapTrap.hpp"

int	main() {
	ClapTrap	daniel("daniel");
	ClapTrap	manu("manu");

	daniel.attack("manu");
	manu.attack("daniel");
	manu.takeDamage(10);
	manu.attack("daniel");
	return 0;
}
