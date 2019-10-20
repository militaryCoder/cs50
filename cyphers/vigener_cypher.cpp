#include "encryption_methods.hpp"

#include <cstring>
#include <iostream>

int main()
{
    std::string inputString;
    std::string keyword;

    std::cout << "Enter string to be encrypted: ";
    std::getline(std::cin, inputString);
    std::cout << "Enter keyword: ";
    std::getline(std::cin, keyword);
    
    const size_t inputStringLength = inputString.size();
    char *outputString = new char[inputStringLength];

    const char space = ' ';
    const size_t keywordLength = keyword.size();

    uint32_t spaceCount = 0;

    for (size_t i = 0; i < inputStringLength; i++)
    {
        if (space == inputString[i])
        {
            spaceCount++;
        }
        uint64_t keywordCurrentCharacterIndex = (i - spaceCount) % keywordLength;

        const uint32_t shiftValue = static_cast<uint32_t>(keyword[keywordCurrentCharacterIndex]);

        outputString[i] = encr_methods::calculateEncryptedLetterPosition(static_cast<uint8_t>(inputString[i]), shiftValue);
    }

    std::cout << outputString << std::endl;
    return 0;
}