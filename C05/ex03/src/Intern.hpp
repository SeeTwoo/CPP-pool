#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &other) {}
Intern::~Intern() {}
Intern	&Intern::operator=(const Intern &other) {
	return *this;
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) {
	static const std::string names[3] = {
		"shrubbery creation",
		"robotomy request", 
		"presidential pardon"
	};

	AForm	*(*constructors[3])(const std::string &) = {
		&createShrubbery,
		&createRobotomy,
		&createPardon
	}

	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return constructors[i](target);
		}
	}
	std::cout << "Form name \"" << formName << "\" not recognized" << std::endl;
	return 0;
}

AForm	*createShrubbery(const std::string &t) {return new ShrubberyCreationForm(t);}
AForm	*createRobotomy(const std::string &t) {return new RobotomyRequestForm(t);}
AForm	*createPardon(const std::string &t) {return new PresdentialPardonForm(t);}
