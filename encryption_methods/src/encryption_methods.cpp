#include "encryption_methods.hpp"

#include <stdexcept>

uint8_t calculateEncryptedLetterPosition(uint8_t letter, uint32_t shiftKey)
{
    const uint8_t alphabetLength = 26u;
    const uint8_t space = ' ';

    if (space == letter)
    {
        return letter;
    }

    if (('A' <= letter && 'Z' >= letter) ||
        ('a' <= letter && 'z' >= letter))
    {
        const uint8_t alphabetASCIIStarterPosition = ('Z' >= letter) ? ('A' - 1) : ('a' - 1);

        const uint8_t classicLetterAlphabeticPosition = letter - alphabetASCIIStarterPosition;
        const uint8_t shiftedLetterPosition = (classicLetterAlphabeticPosition + shiftKey) % alphabetLength;

        return (shiftedLetterPosition + alphabetASCIIStarterPosition);
    }
    else
    {
        throw std::invalid_argument("Invalid character provided");
    }
}