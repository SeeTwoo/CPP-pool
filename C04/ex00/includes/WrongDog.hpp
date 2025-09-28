#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "Animal.hpp"

class WrongDog : public Animal {
	public:
		WrongDog();
		WrongDog(const WrongDog &other);
		WrongDog& operator=(const WrongDog &other);
		~WrongDog();

		void makeSound() const;
};

#endif
