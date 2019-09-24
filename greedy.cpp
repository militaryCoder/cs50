#include <cmath>
#include <cstring>
#include <iostream>
#include <regex>
#include <exception>

const uint32_t DECIMAL_POWER_BASE = 10u;

static inline uint8_t charToInteger(const char value)
{
    if (value <= '0' || value >= '9')
    {
        throw std::out_of_range("Invalid character");
    }

    return (value - '0');
}

float parseFloat(const std::string &buffer)
{
    float finalValue = 0;
    
    std::regex correctValueFormat(R"(\d+(\.\d+)?)");

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
    const uint32_t nominalsCount = 4;
    const uint32_t coinsNominals[nominalsCount] = { 1, 5, 10, 25 };
    
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

            for (int c = 1; c < nominalsCount; c++)
            {
                const int numberOfNominatedCoins = cents / coinsNominals[c];

                if ((numberOfNominatedCoins) < numberOfCoins &&
                    (numberOfNominatedCoins) > 0)
                {
                    numberOfCoins = numberOfNominatedCoins;
                    currentCoinIndex = c;
                }
            }

            totalCoins += numberOfCoins;
            cents -= coinsNominals[currentCoinIndex] * numberOfCoins;
        }

        std::cout << totalCoins << std::endl;
    }
    catch (const std::invalid_argument &invalidArgumentException)
    {
        std::cout << "User entered invalid value" << std::endl;
    }
    
    return 0;
}