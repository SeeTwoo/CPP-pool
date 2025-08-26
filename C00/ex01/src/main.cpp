#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	book;
	std::string	command;

	while (std::getline(std::cin, command)) {
		if (command == "EXIT")
			return (0);
		else if (command == "SEARCH")
			book.searchContact();
		else if (command == "ADD")
			book.addContact();
	}
	return (0);
}
