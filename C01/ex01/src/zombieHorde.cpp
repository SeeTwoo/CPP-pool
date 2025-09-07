#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*Horde;

	if (N <= 0)
		return NULL;
	Horde = new Zombie[N];
	if (!Horde)
		return NULL;
	for (int i = 0; i < N; i++)
		Horde[i].setName(name);
	return Horde;
}
