/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   Bureaucrat.hpp                                      :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: walter </var/spool/mail/walter>             +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureacrat {
	private :
		std::string const	_name;
		char				_grade;
	public :
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const noexcept override
		};
		class GradeTooLowException : public std::exception {
			public :
				const char* what() const noexcept override
		};
		const std::string	getName() const ;
		char				getGrade() const ;

		void		incrementGrade();
		void		decrementGrade();

		Bureaucrat();
		Bureaucrat(int 
		Bureaucrat(const Bureaucrat &);
		Bureaucrat&	operator=(const Bureaucrat &);
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream &, const Bureaucrat &);

#endif
