#include "character_utilities.hpp"

#include <iostream>
#include <stdexcept>

bool charutils::isLetter(uint8_t character)
{
    if (('A' <= character && 'Z' >= character) ||
        ('a' <= character && 'z' >= character))
    {
        return true;
    }
    
    return false;
}

bool charutils::isUpperCase(uint8_t character)
{
    try
    {
        if (!charutils::isLetter(character))
        {
            throw std::invalid_argument("Provided character is not a letter");
        }

        if ('Z' >= character)
        {
            return true;
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return false;
}

bool charutils::isLowerCase(uint8_t character)
{
    try
    {
        if (!charutils::isLetter(character))
        {
            throw std::invalid_argument("Provided character is not a letter");
        }

        if (!charutils::isUpperCase(character))
        {
            return true;
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return false;
}