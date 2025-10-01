#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const int numAnimals = 6;
	Animal* animals[numAnimals];

	//construction
	for (int i = 0; i < numAnimals / 2; i++) {
		animals[i] = new Cat();
	}
	for (int i = numAnimals / 2; i < numAnimals; i++) {
		animals[i] = new Dog();
	}

	std::cout << "--- Testing Deep Copy (Proof of independent Brains) ---" << std::endl;
	Cat tempCat;
	tempCat.setIdea("Original Cat Idea: Chase the mouse!", 0);
	Cat copyCat(tempCat);

	std::cout << "Original Cat's Idea: \"" << tempCat.getIdea(0) << "\"" << std::endl;
	std::cout << "Copied Cat's Idea:   \"" << copyCat.getIdea(0) << "\"" << std::endl;
	
	std::cout << "-> Changing the Original Cat's idea..." << std::endl;
	tempCat.setIdea("New Cat Idea: Time for a nap.", 0);

	std::cout << "Original Cat's New Idea: \"" << tempCat.getIdea(0) << "\"" << std::endl;
	std::cout << "Copied Cat's Idea (should be unchanged): \"" << copyCat.getIdea(0) << "\"" << std::endl;
	std::cout << std::endl;

	std::cout << "--- Testing Assignment Operator Deep Copy ---" << std::endl;
	Dog dogA;
	dogA.setIdea("Dog A: Find a stick!", 0);
	{
		Dog dogB;
		dogB = dogA;
	}
	std::cout << "Dog A should still be fine after Dog B was destructed." << std::endl;
	std::cout << "Dog A's idea: \"" << dogA.getIdea(0) << "\"" << std::endl;
	std::cout << std::endl;

	//deletion
	for (int i = 0; i < numAnimals; i++) {
		delete animals[i];
		std::cout << std::endl;
	}
	return 0;
}
