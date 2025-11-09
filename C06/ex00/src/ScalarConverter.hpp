#include <iostream>

void	Scalar::convert(std::string value) {
	char	*end;
	double	d = std::string(value.c_str(), &end;

	if (value.length() == 1 && !isdigit(value[0]))
		d = value[0];
	if (end == value.c_str() || (*end != '\0' && (*end != 'f' || *(end + 1) != '\0')))
		return (printError());
	
}
