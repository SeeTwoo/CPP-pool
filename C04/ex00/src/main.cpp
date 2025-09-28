#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main() {
	std::cout << "Constructing" << std::endl;
	const Animal* meta = new Animal();
	const Animal* medor = new Dog();
	const Animal* felix = new Cat();


	const WrongCat*	wrongFelix = new WrongCat();
	std::cout << std::endl;

	std::cout << "Testing getType()" << std::endl;
	std::cout << "medor is a: " << medor->getType() << " " << std::endl;
	std::cout << "felix is a: " << felix->getType() << " " << std::endl;
	std::cout << "meta is a: " << meta->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << "Testing makeSound()" << std::endl;
	std::cout << "felix (Cat) says: ";
	felix->makeSound();
	std::cout << "medor (Dog) says: ";
	medor->makeSound();
	std::cout << "meta (Animal) says: ";
	meta->makeSound();
	std::cout << "WrongAnimal says: ";
	wrongFelix->makeSound();
	std::cout << std::endl;

	std::cout << "Destructing" << std::endl;
	delete meta;
	delete medor;
	delete felix;

	return 0;
}
