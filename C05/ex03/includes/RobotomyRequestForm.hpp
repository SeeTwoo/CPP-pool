#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();

	protected:
		void	doAction() const;

	private:
		std::string	_target;
};

#endif
