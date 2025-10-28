#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm &form) const;
		void		executeForm(AForm const &form) const;

		const std::string	&getName() const;
		int					getGrade() const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);

#endif
