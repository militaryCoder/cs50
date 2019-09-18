#include <iostream>

using std::cout,
std::cin,
std::endl;

int main()
{
	cout << "waterminutes: ";
	int waterminutes;
	cin >> waterminutes;
	cout << "bottles: " << waterminutes * 12 << endl;
	return 0;
}