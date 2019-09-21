#include <cmath>
#include <cstring>
#include <iostream>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::regex;

float getFloat()
{
	float finalValue = 0;
	
	std::string buffer;
		
	bool isValueFormatCorrect = false;
	regex* correctValueFormat = new regex("[\\d]+[\\.]?[\\d]{0,2}");

	do
	{
		getline(cin, buffer);
		isValueFormatCorrect = std::regex_match(buffer, *correctValueFormat);
		
		if (isValueFormatCorrect)
		{
			cout << "Format correct" << endl;
		}
		else
		{
			cout << "Format incorrect, please try again" << endl;
		}
	} while (!isValueFormatCorrect);

	delete correctValueFormat;
	correctValueFormat = nullptr;

	int dotIndex;	
	for (int i = 0; i < buffer.size(); i++)
	{
		if (buffer[i] == '.')
		{
			dotIndex = i;
			break;
		}
	}
	
	for (int i = 0; i < dotIndex; i++)
	{
		int decPower = dotIndex - (i + 1);
		bool isDigit = false;

		regex* digits = new regex("\\d");
		isDigit = std::regex_match(std::string(1, buffer[i]), *digits);

		delete digits;
		digits = nullptr;

		if (isDigit)
		{
			float digitValue = ((int)buffer[i] - (int)'0') * pow(10, decPower);
			finalValue += digitValue;
		}
	}
	
	for (int i = (dotIndex + 1); i < buffer.size(); i++)
	{
		if (buffer[i] == ' ')
		{
			continue;
		}
		
		float decPower = dotIndex - i;
		
		bool isDigit = false;

		regex* digits = new regex("\\d");
		isDigit = std::regex_match(std::string(1, buffer[i]), *digits);

		delete digits;
		digits = nullptr;
		
		if (isDigit)
		{
			float digitValue = ((int)buffer[i] - (int)'0') * pow(10, decPower);
			finalValue += digitValue;
		}
	}

	return finalValue;
}

int main()
{
	const int coins[4] = { 1, 5, 10, 25 };
	
	float input = getFloat();
	int cents = input * 100;
	
	int totalCoins = 0;
	while (cents != 0)
	{
		int n = cents / coins[0];
		int currentCoinValue = 0;
		for (int c = 1; c < 4; c++)
		{
			if ((cents / coins[c]) < n
				&& (cents / coins[c]) > 0)
			{
				n = cents / coins[c];
				currentCoinValue = c;
			}
			
		}
		totalCoins += n;
		cents -= coins[currentCoinValue] * n;
	}
	cout << totalCoins << endl;
	return 0;
}