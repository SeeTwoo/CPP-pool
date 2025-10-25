/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   main.c                                              :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	{
		try {
			Bureaucrat	dave(200, "dave");
			std::cout << dave;
		} catch (std::exception &e) {
			std::cout << e.what();
		}
	}
	{
		try {
			Bureaucrat	sam(148, "sam");
			std::cout << sam;
			sam.decrementGrade();
			std::cout << sam;
			sam.decrementGrade();
			std::cout << sam;
			sam.decrementGrade();
			std::cout << sam;
		} catch (std::exception &e) {
			std::cout << e.what();
		}
	}
	{
		try {
			Bureaucrat	saul(50, "saul");
			Form		a28("a28", 60, 60);

			std::cout << a28 << std::endl;
			saul.signForm(a28);
			std::cout << a28 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what();
		}
	}
	return 0;
}
