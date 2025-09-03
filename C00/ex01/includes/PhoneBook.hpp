#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	public:
		void	addContact();
		void	searchContact();
	private:
		Contact	contacts[9];
};

#endif
