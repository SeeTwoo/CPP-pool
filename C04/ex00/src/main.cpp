#include "Animal.cpp"
#include "Cat.cpp"
#include "Dog.cpp"

int	main() {
	const Animal	*meta = new Animal();

	meta->makeSound();
	return 0;
}
