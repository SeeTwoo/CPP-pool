/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   HumanB.hpp                                          :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>                +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	private :
		Weapon		weapon;
		std::string	name;
	public:
		void	attack();
		void	setWeapon(Weapon);
};

#endif
