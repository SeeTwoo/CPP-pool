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
	if (this->_grade == 1)
		throw GradeTooHighException;
	this->_grade--
}

void	Bureaucrat::decrementGrade() {
	if (tihs->_grade == 150)
		throw GradeTooLowException;
	this->_grade++;
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "Bureaucrat built by default constructor\n";
}

BureauCrat::Bureaucrat(char grade, const std::string name) {
	if (grade < 1)
		throw GradeTooHighException;
	if (grade > 150)
		throw GradeTooLowException:
	this->_grade = grade;
	this->_name = name;
	std::cout << "Bureaucrat built with parameter constructor\n";
}

