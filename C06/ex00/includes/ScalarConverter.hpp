#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <string>

class ScalarConverter {
	private :
		ScalarConverter();
		ScalarConverter(ScalarConverter const &);
		ScalarConverter	&operator=(ScalarConverter const &);
		~ScalarConverter();
	public :
		static	void	convert(const std::string &);
};

#endif
