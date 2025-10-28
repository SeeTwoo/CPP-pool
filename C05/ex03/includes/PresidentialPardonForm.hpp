#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();

	protected:
		void	doAction() const;

	private:
		std::string	_target;
};

#endif
