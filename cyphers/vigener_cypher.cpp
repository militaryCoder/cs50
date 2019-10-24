#include "encryption_methods.hpp"

#include <cstring>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    try
    {
        if (argc < 3)
        {
            throw std::invalid_argument("Usage: ./vigener_cypher <message> <keyword>");
        }
        const std::string inputString = argv[1];
        const std::string keyword = argv[2];
        
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
    }
    catch (const std::invalid_argument &exc)
    {
        std::cout << exc.what() << std::endl;
    }
    
    return 0;
}