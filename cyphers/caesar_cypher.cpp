#include <cstring>
#include <exception>
#include <iostream>
#include <regex>
 
const uint8_t CYPHER_SHIFT_KEY_ARGUMENT_INDEX = 1;

uint8_t calculateEncryptedLetterPosition(uint8_t letter, uint32_t shiftKey)
{
    const uint8_t alphabetLength = 26;
    const uint8_t space = ' ';

    if (space == letter)
    {
        return static_cast<uint8_t>(letter);
    }

    if (('A' <= letter && 'Z' >= letter) ||
        ('a' <= letter && 'z' >= letter))
    {
        const uint8_t alphabetASCIIStarterPosition = 'Z' >= letter ? 'A' - 1 : 'a' - 1;

        const uint8_t classicLetterAlphabeticPosition = letter - alphabetASCIIStarterPosition;
        const uint8_t shiftedLetterPosition = (classicLetterAlphabeticPosition + shiftKey) % alphabetLength;

        return shiftedLetterPosition + alphabetASCIIStarterPosition;
    }
    
    throw std::invalid_argument("Invalid character provided");
    
}

int main(int argc, char** argv)
{
    try
    {
    if (argc < 2)
        {
            throw std::invalid_argument("No cypher key provided");
        }
        const uint32_t commandLineArgument = static_cast<uint32_t>(*argv[CYPHER_SHIFT_KEY_ARGUMENT_INDEX]);

        if (0 != commandLineArgument)
        {
            const uint32_t cypherShiftKey = commandLineArgument - '0';
            std::cout << "Cypher key: " << cypherShiftKey << std::endl;

            std::string inputString;
            std::getline(std::cin, inputString);

            const uint32_t outputStringLength = inputString.size() + 1;

            char *outputString = new char[outputStringLength];

            for (size_t i = 0; i < inputString.size(); i++)
            {
                outputString[i] = static_cast<char>(calculateEncryptedLetterPosition(static_cast<uint8_t>(inputString[i]), cypherShiftKey));
            }
            
            outputString[inputString.size()] = '\0';
            std::cout << outputString << std::endl;
        }
        else
        {
            throw std::invalid_argument("No cypher key provided");
        }
        
        
    }
    catch (const std::invalid_argument& exc)
    {
        std::cerr << exc.what() << '\n';
    }

    return 0;
}
