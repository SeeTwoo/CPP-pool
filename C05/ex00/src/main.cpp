#include <iostream>

#include "Bureaucrat.hpp"

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
	return 0;
}
