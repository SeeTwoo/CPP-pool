#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public :
		FragTrap();
		FragTrap(const FragTrap&);
		FragTrap& operator=(const FragTrap&);
		~FragTrap();
		FragTrap(const std::string name);
		void	attack(const std::string &target);
		void	highFivesGuys();
};

#endif
