#ifndef DOG_HPP
# define DOG_HPP

# include "Brain.hpp"
# include "Animal.hpp"

class Dog : public Animal {
	public:
		Brain	*brain;

		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		~Dog();

		void makeSound() const;
};

#endif
