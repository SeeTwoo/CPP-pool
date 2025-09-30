#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main() {
	Animal*	array[4];

	//construction
	for (int i = 0; i < 2; i++)
		array[i] = new Cat();
	for (int i = 2; i < 4; i++)
		array[i] = new Dog();
	std::cout << std::endl;

	//foolin around
	Cat* cat1 = dynamic_cast<Cat*>(array[0]);
    if (cat1) {
		cat1->brain->ideas[0] = "A want to nap in a sunbeam.";
        std::cout << cat1->getType() << " idea: " << cat1->brain->ideas[0] << std::endl;
    }
	std::cout << std::endl;

	//deletion
	for (int i = 0; i < 4; i++)
		delete array[i];
	return 0;
}
