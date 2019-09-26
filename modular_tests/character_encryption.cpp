#include <iostream>

const uint8_t ALPHABET_ASCII_UPPERCASE_STARTING_POSITION = 'A' - 1;
const uint8_t ALPHABET_LENGTH = 26;

uint8_t calculateShiftedLetterPosition(uint8_t letter, uint32_t shift)
{
    return letter + shift;
}
int main()
{
    const int shift = 2;
    const char letter = 'A';

    char finalCharacter = calculateShiftedLetterPosition(letter, shift);
    std::cout << finalCharacter << std::endl;

    return 0;
}