#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	private :
		std::string	ideas[100];
	public :
		Brain();
		Brain(const Brain&);
		Brain &operator=(const Brain &other);
		~Brain();
		void	setIdea(std::string idea, int i);
		std::string	getIdea(int i);
};

#endif
