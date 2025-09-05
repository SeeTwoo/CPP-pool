#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	public:
		void	addContact();
		void	displayPreview();
		void	initPhoneBook();
		void	searchContact();
	private:
		Contact	contacts[8];
		int		currentContact;
		int		contactNumber;
};

#endif
