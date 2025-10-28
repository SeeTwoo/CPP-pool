#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();

	protected:
		void	doAction() const;

	private:
		std::string	_target;
};

#endif
