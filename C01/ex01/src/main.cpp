#include "Zombie.hpp"

int	main(int ac, char **av) {
	Zombie	*horde;
	int		N;
	
	N = std::stoi(av[1]);
	horde = zombieHorde(N, "Karl");
	if (!horde)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i]->announce;
	delete(horde);
	return (0);
}
