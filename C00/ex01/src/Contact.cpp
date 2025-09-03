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
	std::cout.width(10);
	if (s.length() >= 10)
		std::cout << s.substr(0, 9) << ".";
	else
		std::cout << s;
}

void	Contact::printPreview() {
	printFieldPreview(this->_firstName);
	std::cout << "|";
	printFieldPreview(this->_lastName);
	std::cout << "|";
	printFieldPreview(this->_nickName);
	std::cout << "|";
	printFieldPreview(this->_phoneNumber);
	std::cout << "|";
	printFieldPreview(this->_secret);
}
