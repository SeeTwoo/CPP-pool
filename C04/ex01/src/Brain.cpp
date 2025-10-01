#include "Brain.hpp"

void	Brain::setIdea(std::string idea, int index) {
	if (index < 0 || index > 99)
		return ;
	ideas[index] = idea;
}

std::string	Brain::getIdea(int index) {
	if (index < 0 || index > 99)
		return ("");
	return (ideas[index]);
}

Brain::Brain() {
	std::cout << "A Brain has been constructed." << std::endl;
}

Brain::Brain(const Brain &other) {
	*this = other;
	std::cout << "A Brain has been copy-constructed." << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
	if (this != &other)
		for (int i = 0; i < 100 ; i++)
			this->ideas[i] = other.ideas[i];
	std::cout << "A Brain has been assigned." << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "A Brain has been destructed." << std::endl;
}
