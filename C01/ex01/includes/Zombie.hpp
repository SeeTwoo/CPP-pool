#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class	Zombie {
	public :
		Zombie();
		~Zombie();

		void	announce(void);
		void	setName(std::string newName);
	private :
		std::string	name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
