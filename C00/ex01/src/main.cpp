#include <PhoneBook.cpp>
#include <Contact.cpp>

int	main(void) {
	PhoneBook	book;
	std::string	command;

	while (std::getline(std::cin, command)) {
		if (command == "EXIT")
			exit(0);
		if (command == "SEARCH")
			book.search();
	}
}
