#include <cstdlib>
#include <iostream>

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(int ac, char **av) {
	Zombie	*horde;
	int		N;
	
	if (ac != 2) {
		std::cerr << "usage is ./ZombieHorde <numberOfZombies>\n";
		return 1;
	}
	N = std::atoi(av[1]);
	horde = zombieHorde(N, "Karl");
	if (!horde)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
