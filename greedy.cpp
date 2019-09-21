#include <cmath>
#include <cstring>
#include <iostream>
#include <regex>
#include <exception>

const uint32_t DECIMAL_POWER_BASE = 10u;

uint8_t charToInteger(char value)
{
    if (value <= '0' && value >= '9')
    {
        throw std::out_of_range("Invalid character");
    }

    return (value - '0');
}

float parseFloat(std::string buffer)
{
    float finalValue = 0;
    
    std::regex correctValueFormat(R"(\d+(\.\d+)?)");

    // do
    // {
    // 	getline(cin, buffer);
    // 	isValueFormatCorrect = std::regex_match(buffer, *correctValueFormat);
        
    // 	if (isValueFormatCorrect)
    // 	{
    // 		cout << "Format correct" << endl;
    // 	}
    // 	else
    // 	{
    // 		cout << "Format incorrect, please try again" << endl;
    // 	}
    // } while (!isValueFormatCorrect);

    if (!std::regex_match(buffer, correctValueFormat))
    {
        throw std::invalid_argument("Invalid string");
    }

    const int dotIndex = buffer.find('.');
    const int integerPartEndIndex = (std::string::npos == dotIndex) ? buffer.size() : dotIndex;

    for (int i = 0; i < integerPartEndIndex; i++)
    {
        finalValue += charToInteger(buffer[i]) * pow(DECIMAL_POWER_BASE, dotIndex - (i + 1));
    }

    if (std::string::npos != dotIndex)
    {
        for (int i = (dotIndex + 1); i < buffer.size(); i++)
        {
            finalValue += charToInteger(buffer[i]) * pow(DECIMAL_POWER_BASE, dotIndex - i);
        }
    }

    return finalValue;
}

int main()
{
    const int coinsNominals[4] = { 1, 5, 10, 25 };
    
    try
    {
        std::string inputString;
        std::getline(std::cin, inputString);

        float input = parseFloat(inputString);

        uint64_t cents = static_cast<uint64_t>(input * 100);
        
        int totalCoins = 0;
        while (cents != 0)
        {
            int numberOfCoins = cents / coinsNominals[0];
            int currentCoinIndex = 0;

            for (int c = 1; c < 4; c++)
            {
                if ((cents / coinsNominals[c]) < numberOfCoins &&
                    (cents / coinsNominals[c]) > 0)
                {
                    numberOfCoins = cents / coinsNominals[c];
                    currentCoinIndex = c;
                }
            }

            totalCoins += numberOfCoins;
            cents -= coinsNominals[currentCoinIndex] * numberOfCoins;
        }

        std::cout << totalCoins << std::endl;
    }
    catch (std::invalid_argument &invalidArgumentException)
    {
        std::cout << "User entered invalid value" << std::endl;
    }
    
    return 0;
}