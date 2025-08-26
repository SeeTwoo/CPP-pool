#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*dest;

	if (N <= 0)
		return (NULL);
	dest = new Zombie[N];
	if (!dest)
		return (NULL);
	for (i = 0; i < N; i++)
		dest[i].setName(name);
	return (dest);
}
