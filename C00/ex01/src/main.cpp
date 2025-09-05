#include "PhoneBook.hpp"

void	PhoneBook::initPhoneBook() {
	currentContact = 0;
	contactNumber = 0;
}

int	main(void) {
	PhoneBook	book;
	std::string	command;

	book.initPhoneBook();
	while (1) {
		std::cout << "PhoneBook (ADD, SEARCH or EXIT) > ";
		if (!std::getline(std::cin, command))
			return (1);
		if (command == "EXIT")
			return (0);
		else if (command == "SEARCH")
			book.searchContact();
		else if (command == "ADD")
			book.addContact();
	}
	return (0);
}
