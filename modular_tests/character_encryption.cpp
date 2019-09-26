#include <exception>
#include <iostream>

const uint8_t ALPHABET_LENGTH = 26;

uint8_t calculateShiftedLetterPosition(uint8_t letter, uint32_t shiftKey)
{
    if (('A' <= letter && 'Z' >= letter) ||
        ('a' <= letter && 'z' >= letter))
    {
        const uint8_t alphabetASCIIStarterPosition = ('Z' >= letter) ? ('A' - 1) : ('a' - 1);

        const uint8_t classicLetterAlphabeticPosition = letter - alphabetASCIIStarterPosition;
        const uint8_t shiftedLetterPosition = (classicLetterAlphabeticPosition + shiftKey) % 26;
        const uint8_t finalLetterPosition = shiftedLetterPosition + alphabetASCIIStarterPosition;

        return finalLetterPosition;
    }
    else
    {
        throw std::invalid_argument("Invalid character provided");
    }
}

int main()
{
    const uint32_t shift = 2;
    

    try
    {
        char letter;
        std::cin >> letter;
        char finalCharacter = calculateShiftedLetterPosition(letter, shift);
        std::cout << finalCharacter << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}