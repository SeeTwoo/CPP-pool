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
#include <string.h>

int	main(int ac, char **av) {
	if (ac != 2)
		return (1);
	try {
		if (strlen(av[1]) % 2 == 0)
			throw std::runtime_error("even string len");
	} catch (std::exception &e) {
		std::cerr << e.what();
	}
	return (0);
}
