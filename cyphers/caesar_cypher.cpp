#include "encryption_methods.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

const uint8_t CYPHER_SHIFT_KEY_ARGUMENT_INDEX = 1u;

int main(int argc, char** argv) {
    try {
        if (argc < 2) {
            throw std::invalid_argument("No cypher key provided.");
        }

        const uint32_t cypherShiftKey = std::atoi(argv[CYPHER_SHIFT_KEY_ARGUMENT_INDEX]);

        if (0 != cypherShiftKey) {
            std::string inputString;
            std::cout << "Enter string that should be encrypted.\n";
            std::getline(std::cin, inputString);

            std::string outStr;

            for (const auto &ch : inputString) {
                    outStr += std::isalpha(ch) ? static_cast<char>(encr_methods::calculateEncryptedLetterPosition(ch, cypherShiftKey))
                        : ch;
            }
            
            std::cout << outStr << std::endl;
        }
        else throw std::invalid_argument("Cypher should be more than zero.");
    }
    catch (const std::invalid_argument &exc) {
        std::cerr << exc.what() << '\n';
    }

    return 0;
}
