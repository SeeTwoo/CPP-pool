#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(NULL));
    try {
        std::cout << "Testing Instantiation Failures" << std::endl;
        Bureaucrat tooHigh("High", 0);
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    try {
        Bureaucrat tooLow("Low", 151);
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\nTesting Signing and Execution" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat middleManager("Middle Manager", 50);
    Bureaucrat trainee("Trainee", 148);

    ShrubberyCreationForm shrub("Garden");

    trainee.signForm(shrub);
    trainee.executeForm(shrub);

    middleManager.signForm(shrub);
    trainee.executeForm(shrub);
    middleManager.executeForm(shrub);

    std::cout << "\nTesting Intern" << std::endl;
    Intern someRandomIntern;
    AForm* rrf;
    AForm* ppf;
    AForm* scf;
    AForm* unknown;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    ppf = someRandomIntern.makeForm("presidential pardon", "Ford");
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    unknown = someRandomIntern.makeForm("invalid form", "Nowhere");

    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    if (ppf) {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }
    if (scf) {
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }

    return 0;
}
