/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   Form.hpp                                            :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string   _name;
		bool                _isSigned;
		const int           _gradeSign;
		const int           _gradeExec;

	public:
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
		};

		Form();
		Form(const std::string name, int gradeSign, int gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string   getName() const;
		bool                getIsSigned() const;
		int                 getGradeSign() const;
		int                 getGradeExec() const;

		void    beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif
