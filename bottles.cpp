#include <iostream>

int main()
{
	std::cout << "waterminutes: ";
	int waterminutes;
	cin >> waterminutes;
	std::cout << "bottles: " << waterminutes * 12 << std::endl;
	return 0;
}