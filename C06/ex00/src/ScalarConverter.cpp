#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>

static bool isCharLiteral(const std::string &s) {
	return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isIntLiteral(const std::string &s) {
	std::istringstream iss(s);
	int val;

	iss >> val;
	return iss.eof() && !iss.fail();
}

static bool isFloatLiteral(const std::string &s) {
	std::string core = s.substr(0, s.length() - 1);
	std::istringstream iss(core);
	float val;

	if (s == "-inff" || s == "+inff" || s == "nanf")
		return true;
	if (s[s.length() - 1] != 'f')
		return false;
	iss >> val;
	return iss.eof() && !iss.fail();
}

static bool isDoubleLiteral(const std::string &s) {
	std::istringstream iss(s);
	double val;

	if (s == "-inf" || s == "+inf" || s == "nan")
		return true;
	iss >> val;
	return iss.eof() && !iss.fail();
}

static void printChar(double d) {
	std::cout << "char: ";
	if (std::isnan(d) || d < std::numeric_limits<char>::min()
		|| d > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

static void printInt(double d) {
	std::cout << "int: ";
	if (std::isnan(d) || d < std::numeric_limits<int>::min()
		|| d > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double d) {
	float f = static_cast<float>(d);

	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inff" : "+inff") << std::endl;
	else {
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
}

static void printDouble(double d) {
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
	double value = 0.0;

	if (isCharLiteral(literal))
		value = static_cast<double>(literal[1]);
	else if (isIntLiteral(literal))
		value = std::atoi(literal.c_str());
	else if (isFloatLiteral(literal))
		value = static_cast<double>(std::atof(literal.c_str()));
	else if (isDoubleLiteral(literal))
		value = std::atof(literal.c_str());
	else {
		std::cout << "Invalid literal" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

