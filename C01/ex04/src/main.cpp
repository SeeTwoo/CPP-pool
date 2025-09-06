/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   main.cpp                                            :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

int	main(int ac, char **av) {
	if (ac != 4) {
        std::cerr << "Usage: " << av[0] << " <file> <search> <replace>\n";
        return 1;
    }

    std::ifstream in(av[1]);
    if (!in) {
        std::cerr << "Error: cannot open input file\n";
        return 1;
    }

    std::string replace = ".replace";
	std::string filename = std::string(av[1]) + replace;
    std::ofstream out(filename.c_str());

    std::string line;
    std::string a = av[2];
    std::string b = av[3];

    while (std::getline(in, line)) {
        size_t pos = 0;
        while ((pos = line.find(a, pos)) != std::string::npos) {
            line.replace(pos, a.length(), b);
            pos += b.length();
        }
        out << line << "\n";
    }
	return 0;
}
