#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool			_signed;
		const int		_gradeSign;
		const int		_gradeExec;
	protected:
		virtual void	doAction() const = 0;
	public:
		void			beSigned(const Bureaucrat &b);
		void			execute(Bureaucrat const &executor) const;

		const std::string	&getName() const;
		bool				isSigned() const;
		int					getGradeSign() const;
		int					getGradeExec() const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
		AForm(const std::string &name, int gradeSign, int gradeExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
