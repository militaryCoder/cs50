#include <iostream>

int main()
{
	int height;
	std::cin >> height;
	for (int h = 0; h < height; h++)
	{
		for (int s = 0; s < (height - h); s++)
		{
			std::cout << " ";
		}
		for (int ch = 0; ch <= h; ch++)
		{
			std::cout << "#";
		}
		std::cout << std::endl;
	}
	return 0;
}