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
			throw ("even string len");
	} catch (char *error) {
		std::cerr << error;
	}
	return (0);
}
