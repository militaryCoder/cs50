#include <iostream>
#include <cstring>

using std::cout,
std::cin,
std::endl;

char charDigits[10] =
{
	'0', '2', '3',
	'4', '5', '6',
	'7', '8', '9'
};

float getFloat()
{
	float value = 0;
	
	const int LENGTH = 16;
	char buffer[LENGTH];
	cin.getline(buffer, LENGTH);
	int dotIndex = LENGTH;
	
	for (int i = 0; i < LENGTH; i++)
	{
		if (buffer[i] == '.')
		{
			dotIndex = i;
		}
	}
	
	for (int i = 0; i < dotIndex; i++)
	{
		int decPower = dotIndex - i;
		bool isDigit = false;
		
		for (int c = 0; c < 10; c++)
		{
			if (buffer[i] == digits[c])
			{
				isDigit = true;
			}
		}
		
		if (isDigit)
		{
			value += (int)buffer[i] * pow(10, decPower);
	}
}

int main()
{
	getFloat();
	return 0;
}