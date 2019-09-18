#include <iostream>

using std::cin,
std::cout,
std::endl;

int main()
{
	int height;
	cin >> height;
	for (int h = 0; h < height; h++)
	{
		for (int s = 0; s < (height - h); s++)
		{
			cout << " ";
		}
		for (int ch = 0; ch <= h; ch++)
		{
			cout << "#";
		}
		cout << endl;
	}
	return 0;
}