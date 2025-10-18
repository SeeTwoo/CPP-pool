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
		std::string	getName();
		char		getGrade();
		void		incrementGrade();
		void		decrementGrade();

		Bureaucrat();
		Bureaucrat(const Bureaucrat &);
		Bureaucrat&	operator=(const Bureaucrat &);
		~Bureaucrat();
};

#endif
