/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   Bureaucrat.cpp                                      :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: walter </var/spool/mail/walter>             +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

const char *GradeTooHighException::what() const noexcept override {
	return "Grade too high";
}

const char *GradeTooLowException::what() const noexcept override {
	return "Grade too low";
}

void	Bureaucrat::incrementGrade() {
	this->_grade
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "Bureaucrat built by default constructor\n";
}

BureauCrat::Bureaucrat(char grade, const std::string name) {
	if (grade < 0)
		throw GradeTooHighException;
	if (grade > 150)
		throw GradeTooLowException:
	this->_grade = grade;
	this->_name = name;
	std::cout << "Bureaucrat built with parameter constructor\n";
}

