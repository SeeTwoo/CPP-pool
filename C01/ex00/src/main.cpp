#include "Zombie.hpp"

int	main(void) {
	Zombie	*zombie;

	zombie = newZombie("Karl");
	if (!zombie)
		return (1);
	zombie->announce();
	randomChump("Daniel");
	delete(zombie);
}
