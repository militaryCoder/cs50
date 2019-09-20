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
	regex* correctValueFormat = new regex("[\\d]+\\.[\\d]+");

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
	cout << "Dot index is: " << dotIndex << endl;
	
	for (int i = 0; i < dotIndex; i++)
	{
		cout << "---------- " << i << endl;

		int decPower = dotIndex - (i + 1);
		bool isDigit = false;
		
		cout << "Got character [" << buffer[i] << "]" << endl;
		
		regex* digits = new regex("\\d");
		isDigit = std::regex_match(std::string(1, buffer[i]), *digits);

		delete digits;
		digits = nullptr;

		if (isDigit)
		{
			cout << "Character [" << buffer[i] << "] is digit [" << ((int)buffer[i] - (int)'0') << "]" << endl;

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
			cout << "Character [" << buffer[i] << "] is digit [" << ((int)buffer[i] - (int)'0') << "]" << endl;

			float digitValue = ((int)buffer[i] - (int)'0') * pow(10, decPower);
			finalValue += digitValue;
		}
	}

	return finalValue;
}

int main()
{
	cout << getFloat() << endl;
	return 0;
}