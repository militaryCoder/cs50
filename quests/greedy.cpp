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

double parseFloat(const std::string &buffer)
{
    double finalValue = 0;
    
    std::regex correctValueFormat(R"(\d+(\.\d+)?)");

    if (!std::regex_match(buffer, correctValueFormat))
    {
        throw std::invalid_argument("Invalid string");
    }

    const size_t dotIndex = buffer.find('.');
    const size_t integerPartEndIndex = (std::string::npos == dotIndex) ? buffer.size() : dotIndex;

    for (size_t i = 0; i < integerPartEndIndex; i++)
    {
        finalValue += charToInteger(buffer[i]) * pow(DECIMAL_POWER_BASE, dotIndex - (i + 1));
    }

    if (std::string::npos != dotIndex)
    {
        for (size_t i = (dotIndex + 1); i < buffer.size(); i++)
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

        double input = parseFloat(inputString);

        uint32_t cents = static_cast<uint32_t>(input * 100);
        
        const uint32_t nominalsCount = 4;
        const uint32_t coinsNominals[nominalsCount] = { 1, 5, 10, 25 };

        uint32_t totalCoins = 0;
        while (cents != 0)
        {
            uint32_t numberOfCoins = cents / coinsNominals[0];
            uint8_t currentCoinIndex = 0;

            for (uint32_t c = 1; c < nominalsCount; c++)
            {
                const uint32_t numberOfNominatedCoins = cents / coinsNominals[c];

                if ((numberOfNominatedCoins < numberOfCoins) &&
                    (numberOfNominatedCoins > 0))
                {
                    numberOfCoins = numberOfNominatedCoins;
                    currentCoinIndex = static_cast<uint32_t>(c);
                }
            }

            totalCoins += numberOfCoins;
            cents -= coinsNominals[currentCoinIndex] * numberOfCoins;
        }

        std::cout << totalCoins << std::endl;
    }
    catch (const std::invalid_argument &invalidArgumentException)
    {
        std::cout << invalidArgumentException.what();
    }
    
    return 0;
}
