#include <cstring>
#include <exception>
#include <iostream>
#include <regex>
 
const uint8_t CYPHER_SHIFT_KEY_ARGUMENT_INDEX = 1;

const uint8_t ALPHABET_ASCII_STARTING_POSITION = 'A' - 1;
const uint8_t ALPHABET_LENGTH = 26;

uint8_t calculateCypheredLetterPosition(uint8_t letter, uint32_t key)
{
    return (((letter - ALPHABET_ASCII_STARTING_POSITION) + key) % ALPHABET_LENGTH) + ALPHABET_ASCII_STARTING_POSITION;
}

//Uncomment main() to use feature from line 25
int main(/* int argc, char** argv */)
{
    try
    {
    	/*
    	Taking cypher key value directly from command line program execution arguments
    	Does not work on mobile devices
    	*/
        //const uint64_t cypherShiftKey = (uint64_t)argv[CYPHER_SHIFT_KEY_ARGUMENT_INDEX];

		uint32_t cypherShiftKey;
		std::cout << "1";
		std::cin >> cypherShiftKey;

        std::string inputString;
        std::cout << "2";
        std::getline(std::cin, inputString);
        
        std::regex inputTemplate("(\\w)+");
        
        if (std::regex_match(inputString, inputTemplate))
        {
        	std::string outputString[inputString.size()];
        
        	for (size_t i = 0; i < inputString.size(); i++)
        	{
            	outputString[i] = calculateCypheredLetterPosition(inputString[i], cypherShiftKey);
        	}
        	std::cout << outputString << std::endl;
        }
        else
        {
        	throw std::invalid_argument("Entered string that did not matched the template");
        }
    }
    catch(const std::invalid_argument& exc)
    {
        std::cerr << exc.what() << '\n';
    }

    return 0;
}