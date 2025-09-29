#include "Brain.hpp"

Brain::Brain() : type("Generic Brain") {
	std::cout << "A Brain has been constructed." << std::endl;
}

Brain::Brain(const Brain &other) {
	*this = other;
	std::cout << "A Brain has been copy-constructed." << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "A Brain has been assigned." << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "A Brain has been destructed." << std::endl;
}
