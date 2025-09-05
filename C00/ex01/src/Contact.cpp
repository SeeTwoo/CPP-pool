/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   Contact.cpp                                         :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>                +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

void	printFieldPreview(std::string s) {
	if (s.length() >= 10) {
		std::cout.width(9);
		std::cout << s.substr(0, 9) << ".";
	} else {
		std::cout.width(10);
		std::cout << s;
	}
}

void	Contact::printPreview() {
	printFieldPreview(this->_firstName);
	std::cout << "|";
	printFieldPreview(this->_lastName);
	std::cout << "|";
	printFieldPreview(this->_nickName);
	std::cout << "|\n";
}

void	Contact::displayFullContact() {
	std::cout << "first name : " << _firstName << std::endl;
	std::cout << "last name : " << _lastName << std::endl;
	std::cout << "nickname : " << _nickName << std::endl;
	std::cout << "phone number : " << _phoneNumber << std::endl;
	std::cout << "secret : " << _secret << std::endl;
}

void	Contact::setValues(std::string first, std::string last, std::string nick, std::string number, std::string secret) {
	_firstName = first;
	_lastName = last;
	_nickName = nick;
	_phoneNumber = number;
	_secret = secret;
}
