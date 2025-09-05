#include "PhoneBook.hpp"
#include <cstdlib>

void	PhoneBook::addContact() {
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	secret;

	std::cout << "enter first name\n";
	std::getline(std::cin, firstName);
	std::cout << "enter last name\n";
	std::getline(std::cin, lastName);
	std::cout << "enter nick name\n";
	std::getline(std::cin, nickName);
	std::cout << "enter phone number\n";
	std::getline(std::cin, phoneNumber);
	std::cout << "enter secret\n";
	std::getline(std::cin, secret);
	contacts[currentContact].setValues(
		firstName,
		lastName,
		nickName,
		phoneNumber,
		secret
	);
	currentContact++;
	if (currentContact == 8)
		currentContact = 0;
	if (contactNumber < 8)
		contactNumber++;
}

void	PhoneBook::displayPreview() {
	std::cout << " |" << "first name|" << " last name|" << " nick name|\n";
	for (int i = 0; i < contactNumber; i++) {
		std::cout << i << "|";
		contacts[i].printPreview();
	}
}

void	PhoneBook::searchContact() {
	std::string	indexString;
	int			contactIndex;

	this->displayPreview();
	std::cout << "Enter contacts index > ";
	std::getline(std::cin, indexString);
	if (!std::isdigit(indexString[0])) {
		std::cerr << "The index must only contain digits\n";
		return ;
	}
	contactIndex = (int)std::atoi(indexString.c_str());
	if (contactIndex < 0 || contactIndex >= contactNumber) {
		std::cerr << "The contact at the index must exist\n";
		return ;
	}
	contacts[contactIndex].displayFullContact();
}
