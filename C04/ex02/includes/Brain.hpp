#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	private:
		std::string	ideas[100];
	public :
		void		setIdea(std::string idea, int index);
		std::string	getIdea(int index);

		Brain();
		Brain(const Brain&);
		Brain &operator=(const Brain &other);
		~Brain();
};

#endif
