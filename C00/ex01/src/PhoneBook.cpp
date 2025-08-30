#include "PhoneBook.hpp"

PhoneBook::addContact() {
	std::cout << "adding a contact\n";
}



PhoneBook::displayPreview() {
	for (int i = 0; i++; i <= this->currentIndex) {
		printFieldPreview(this->contacts[i]->_firstName;);
		std::cout << "|";
		printFieldPreview(this->contacts[i]->_lastName;);
		std::cout << "|";
		printFieldPreview(this->contacts[i]->_nickName;);
		std::cout << "|";
		printFieldPreview(this->contacts[i]->_phoneNumber;);
		std::cout << "|";
		printFieldPreview(this->contacts[i]->_secret;);
		std::cout << "|";
	}
}

PhoneBook::searchContact() {
	std::string	indexString;
	int			contactIndex;

	this->displayPreview();
	std::cout << "Enter contact index > ";
	indexString = std::getline(std::cin, std::indexString);
	if (!index) {
		std::cerr << "getline failed \n";
		return ;
	}
	if (!std::isdigit(indexString[0])) {
		std::cerr << "The index must only contain digits\n";
		return ;
	}
	contactIndex = std::stoi(indexString);
	if (contactIndex < 0 || contactIndex > 7) {
		std::cerr << "The index must be in the 0 to 7 range\n";
		return ;
	}
	this->displayContact(contactIndex);
}
