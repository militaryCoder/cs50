#include "../../include/encryption_methods.hpp"

#include <cstring>
#include <exception>
#include <iostream>
#include <regex>

const uint8_t CYPHER_SHIFT_KEY_ARGUMENT_INDEX = 1u;

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
