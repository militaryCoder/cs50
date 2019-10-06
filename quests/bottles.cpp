#include <iostream>

int main()
{
	std::cout << "waterminutes: ";
	uint32_t waterminutes;

	std::cin >> waterminutes;

	std::cout << "bottles: " << waterminutes * 12 << std::endl;
	return 0;
}