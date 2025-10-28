#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeSign, int gradeExec)
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

AForm &AForm::operator=(const AForm &other) {
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getGradeSign() const { return _gradeSign; }
int AForm::getGradeExec() const { return _gradeExec; }

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeExec)
		throw AForm::GradeTooLowException();
	doAction();
}

const char *AForm::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char *AForm::GradeTooLowException::what() const throw() { return "Grade too low"; }
const char *AForm::FormNotSignedException::what() const throw() { return "Form not signed"; }

std::ostream &operator<<(std::ostream &out, const AForm &f) {
	out << f.getName() << ", form signed: " << f.isSigned()
	    << ", grade to sign: " << f.getGradeSign()
	    << ", grade to execute: " << f.getGradeExec();
	return out;
}

