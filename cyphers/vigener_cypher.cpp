#include "encryption_methods.hpp"

#include <cstring>
#include <iostream>

int main()
{
    std::string inputString;
    std::string keyword;

    std::cout << "Enter string to be encrypted: ";
    std::cin >> inputString;
    std::cout << "Enter keyword: ";
    std::cin >> keyword;
    
    const uint8_t inputStringLength = inputString.size();
    char *outputString = new char[inputStringLength];

    const char space = ' ';
    const uint32_t keywordLength = keyword.size();

    uint8_t spaceCount = 0;

    for (size_t i = 0; i < inputStringLength; i++)
    {
        if (space == inputString[i])
        {
            ++spaceCount;
        }
        uint8_t keywordCurrentCharacterIndex = (i - spaceCount) % keywordLength;

        outputString[i] = calculateEncryptedLetterPosition(static_cast<uint8_t>(inputString[i]), keyword[keywordCurrentCharacterIndex]);
    }

    return 0;
}