#include <cmath>
#include <cstdlib>
#include <iostream>
#include <exception>

int main() {
    std::string inputString;
    std::getline(std::cin, inputString);
    const float input = std::atof(inputString.c_str());
    
    const int NOMINALS_COUNT = 4;
    const int coinsNominals[NOMINALS_COUNT] = { 1, 5, 10, 25 };

    int cents = static_cast<int>(input * 100);
    int totalCoins = 0;
    for (size_t i = 3; i >= 0 && cents != 0; i--) {
        totalCoins += cents / coinsNominals[i];
        cents %= coinsNominals[i];
    }
    std::cout << totalCoins << '\n';
    
    return 0;
}
