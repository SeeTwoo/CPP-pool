#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
	public:
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();
		static void	convert(std::string);
};

#define
