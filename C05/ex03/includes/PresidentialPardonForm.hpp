#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm {
	protected:
		void	doAction() const;
	private:
		std::string	_target;
	public:
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
};

#endif
