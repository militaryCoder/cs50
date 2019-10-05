#include "../../include/encryption_methods.hpp"
#include <iostream>

int main()
{
    const uint32_t shift = 2;
    
    try
    {
        char letter;
        std::cin >> letter;
        char finalCharacter = calculateEncryptedLetterPosition(letter, shift);
        std::cout << finalCharacter << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}