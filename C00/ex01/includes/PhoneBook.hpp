#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	public:
//		PhoneBook();
//		~PhoneBook();
//		PhoneBook(const PhoneBook&);
//		PhoneBook& operator=(const PhoneBook&);

		void	addContact(void);
		void	searchContact(void);
	private:
		Contact	contacts[9];
};

#endif
