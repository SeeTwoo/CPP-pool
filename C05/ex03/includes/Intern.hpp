#ifndef INTERN_HPP
# define INTERN_HPP

class	AForm;

class	Intern {
	public :
		Intern();
		Intern(const Intern &);
		Intern	&operator=(const Intern &);
		~Intern();
		AForm	*makeForm(std::string, std::string);
};

#endif
