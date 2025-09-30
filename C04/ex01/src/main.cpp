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

	//foolin around
	Cat* cat1 = dynamic_cast<Cat*>(array[0]);
    if (cat1) {
        cat1->brain->setIdea("I want to nap in a sunbeam.", 0);
        std::cout << cat1->getType() << " idea: " << cat1->brain->getIdea(0) << std::endl;
    }

	//deletion
	for (int i = 0; i < 4; i++)
		delete array[i];
	return 0;
}
