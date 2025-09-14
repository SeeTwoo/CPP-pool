#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class	ClapTrap {
	private :
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;
	public :
		ClapTrap();
		ClapTrap(const Claptrap&);
		ClapTrap& operator=(const ClapTrap&);
		~ClapTrap();
		ClapTrap(const std::string);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif

