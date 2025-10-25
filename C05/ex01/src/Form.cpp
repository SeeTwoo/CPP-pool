/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   Form.cpp                                            :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>                +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeSign(150), _gradeExec(150) {
	std::cout << "Form constructed with default constructor\n";
}

Form::Form(const std::string name, int gradeSign, int gradeExec)
    : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GradeTooHighException();
    if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
	std::cout << "Form constructed with value constructor\n";
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
	std::cout << "Form constructed with copy constructor\n";
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {
	std::cout << "Form destructed with default destructor\n";
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form's grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form's grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << f.getGradeSign()
       << ", exec grade: " << f.getGradeExec();
    return os;
}

const std::string Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeSign() const {
    return _gradeSign;
}

int Form::getGradeExec() const {
    return _gradeExec;
}
