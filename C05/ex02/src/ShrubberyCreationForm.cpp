#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::doAction() const {
	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out)
		return;
	out << "   ccee88oo\n"
	       "  C8O8O8Q8PoOb o8oo\n"
	       " dOB69QO8PdUOpugoO9bD\n"
	       "CgggbU8OU qOp qOdoUOdcb\n"
	       "    6OuU  /p u gcoUodpP\n"
	       "      \\\\//  /douUP\n"
	       "        \\\\////\n"
	       "         |||/\\\n"
	       "         |||\\/ \n"
	       "         |||||\n"
	       "   .....//||||\\....\n";
	out.close();
}
