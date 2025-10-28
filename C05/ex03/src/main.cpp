#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
	std::srand(std::time(0));

	Bureaucrat b1("Alice", 1);
	Bureaucrat b2("Bob", 140);

	ShrubberyCreationForm f1("home");
	RobotomyRequestForm    f2("Marvin");
	PresidentialPardonForm f3("Arthur Dent");

	b2.signForm(f1);
	b2.executeForm(f1);

	b1.signForm(f2);
	b1.executeForm(f2);

	b1.signForm(f3);
	b1.executeForm(f3);

	return 0;
}
