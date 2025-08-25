#include <PhoneBook.cpp>
#include <Contact.cpp>

int	main(void) {
	PhoneBook	book;
	std::string	command;

	while (std::getline(std::cin, command)) {
		if (command == "EXIT")
			exit(0);
		else if (command == "SEARCH")
			book.search();
		else if (command == "ADD")
	}
}
