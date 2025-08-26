#include "Zombie.cpp"

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";`
}

Zombie	*newZombie(std::string "name") {
	Zombie	*dest;

	dest = new();
	if (!dest)
		return (NULL);
	dest.name = name;
	return (dest);
}

void	Zombie::randomChump(std::string name) {
	Zombie	zombie;

	zombie.name = "Karl";
	zombie.announce();
}
