/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   shit_hash.cpp                                       :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>                +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

unsigned int	shit_hash(std::string s) {
	return ((s[3] + s.length()) % 4);
}

int	main() {
	std::string	a = "DEBUG";
	std::string b = "INFO";
	std::string	c = "WARNING";
	std::string	d = "ERROR";

	std::cout << shit_hash(a) << "\n";
	std::cout << shit_hash(b) << "\n";
	std::cout << shit_hash(c) << "\n";
	std::cout << shit_hash(d) << "\n";
	return 0;
}
