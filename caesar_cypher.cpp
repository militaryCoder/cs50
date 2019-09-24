#include <cstring>
#include <exception>
#include <iostream>
 
const uint8_t CYPHER_SHIFT_KEY_ARGUMENT_INDEX = 1;

const uint8_t ALPHABET_ASCII_STARTING_POSITION = 'A' - 1;
const uint8_t ALPHABET_LENGTH = 26;

uint8_t calculateCypheredLetterPosition(uint8_t letter, uint32_t key)
{
    return (((letter - ALPHABET_ASCII_STARTING_POSITION) + key) % ALPHABET_LENGTH) + ALPHABET_ASCII_STARTING_POSITION;
}

int main(int argc, char argv[])
{
    try
    {
        const uint32_t cypherShiftKey = (uint32_t)argv[CYPHER_SHIFT_KEY_ARGUMENT_INDEX];

        std::string inputString;
        std::getline(std::cin, inputString);

        std::string outputString[inputString.size()];
        
        for (size_t i = 0; i < inputString.size(); i++)
        {
            outputString[i] = calculateCypheredLetterPosition(inputString[i], cypherShiftKey);
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}