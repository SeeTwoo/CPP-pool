#include "PhoneBook.hpp"

PhoneBook::addContact() {
	std::cout << "enter first name\n";
	this->contacts[0]->_firstName = std::getline(std::cin, this->_firstName);
	std::cout << "enter last name\n";
	this->contacts[0]->_lastName = std::getline(std::cin, this->_lastName);
	std::cout << "enter nick name\n";
	this->contacts[0]->_nickName = std::getline(std::cin, this->_nickName);
	std::cout << "enter phone number\n";
	this->contacts[0]->_phoneNumber= std::getline(std::cin, this->_phoneNumber);
	std::cout << "secret";
	this->contacts[0]->_secret= std::getline(std::cin, this->_secret);
}

PhoneBook::displayPreview() {
	this.contacts[0].printPreview();
}

PhoneBook::searchContact() {
	std::string	indexString;
//	int			contactIndex;

	this->displayPreview();
	/*std::cout << "Enter contacts index > ";
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
	}*/
//k	this->displayContact(contactIndex);
}
