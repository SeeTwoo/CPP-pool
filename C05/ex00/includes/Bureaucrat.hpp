#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
	private :
		std::string const	_name;
		int					_grade;
	public :
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				const char* what() const throw();
		};
		const std::string	getName() const ;
		int					getGrade() const ;

		void		incrementGrade();
		void		decrementGrade();

		Bureaucrat();
		Bureaucrat(int, const std::string);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat&	operator=(const Bureaucrat &);
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream &, const Bureaucrat &);

#endif
