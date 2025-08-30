#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	public:
		void	addContact(void);
		void	searchContact(void);
	private:
		Contact	contacts[9];
		int		currentIndex = 0;
};

#endif
