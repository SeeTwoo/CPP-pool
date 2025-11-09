#include "iter.hpp"
#include "utils.hpp"
#include <string>

int	main(void)
{
	int				arrInt[5] = {1, 2, 3, 4, 5};
	std::string		arrStr[3] = {"Hello", "World", "!"};
	const int		arrConst[4] = {10, 20, 30, 40};

	std::cout << "Original int array:" << std::endl;
	iter(arrInt, 5, printElement<int>);

	std::cout << "\nIncrementing int array:" << std::endl;
	iter(arrInt, 5, increment<int>);
	iter(arrInt, 5, printElement<int>);

	std::cout << "\nString array:" << std::endl;
	iter(arrStr, 3, printElement<std::string>);

	std::cout << "\nConst array:" << std::endl;
	iter(arrConst, 4, printElement<int>);

	return 0;
}
