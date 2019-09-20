#include <cmath>
#include <cstring>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int DIGITS_NUMBER = 10;
char charDigits[DIGITS_NUMBER] =
{
	'0', '1', '2', '3', '4',
	'5', '6', '7', '8', '9'
};

const int LEGAL_CHARS_NUMBER = 11;
char legalChars[LEGAL_CHARS_NUMBER] =
{
	'0', '1', '2', '3',
	'4', '5', '6', '7',
	'8', '9', '.'

};

float getFloat()
{
	float finalValue = 0;
	
	const int LENGTH = 16;
	string buffer;
	getline(cin, buffer);
	int dotIndex;
	
	for (int i = 0; i < LENGTH; i++)
	{
		bool isCharValid = false;
		for (int l = 0; l < LEGAL_CHARS_NUMBER; l++)
		{
			if (buffer[i] == legalChars[l])
			{
				isCharValid = true;
			}
		}

		if (buffer[i] == ' ' && buffer[i + 1] != ' ')
		{
			cout << "Detected useless space, try entering value again" << endl;
			getline(cin, buffer);
			i = 0;
		}
		else
		{
			continue;
		}
		
		if (!isCharValid)
		{
			cout << "Illegal character [" << buffer[i] << "] detected at position " << i << endl;
			cout << "Enter another value" << endl;
			getline(cin, buffer);
			i = 0;
		}
	}

	for (int i = 0; i < LENGTH; i++)
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
		if (buffer[i] == ' ')
		{
			continue;
		}
		int decPower = dotIndex - (i + 1);
		bool isDigit = false;
		
		cout << "Got character [" << buffer[i] << "]" << endl;
		for (int c = 0; c < DIGITS_NUMBER; c++)
		{
			if (buffer[i] == charDigits[c])
			{
				isDigit = true;
				cout << "Character [" << buffer[i] << "] is digit [" << ((int)buffer[i] - (int)'0') << "]" << endl;
			}
		}
		
		if (isDigit)
		{
			float digitValue = ((int)buffer[i] - (int)'0') * pow(10, decPower);
			finalValue += digitValue;
		}
	}
	
	for (int i = (dotIndex + 1); i < LENGTH; i++)
	{
		if (buffer[i] == ' ')
		{
			continue;
		}
		
		float decPower = dotIndex - i;
		
		bool isDigit = false;
		for (int c = 0; c < DIGITS_NUMBER; c++)
		{
			if (buffer[i] == charDigits[c])
			{
				isDigit = true;
			}
		}
		
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
	cout << getFloat();
	return 0;
}