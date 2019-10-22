#include <fstream>
#include <iostream>
#include <vector>

const int32_t binarySearch(const int32_t value, const std::vector<int32_t> vector, const size_t size) {
    if (size < 0) {
        throw std::invalid_argument("Given argument [size] is invalid - cannot be less than minimal treshold");
    }

    uint32_t midPoint = size / 2;
    std::cout << "Starting at position [" << midPoint << "]\n";
    
    while (vector[midPoint] != value) {
        const int32_t accessedValue = vector[midPoint];
        std::cout << "Accessed value [" << accessedValue << "] at index [" << midPoint << "]\n";
        if (value > accessedValue) {
            midPoint = midPoint + ((size - midPoint) / 2);
        }
        else if (value < accessedValue) {
            midPoint = midPoint - ((1 == midPoint) ? 1 : midPoint / 2);
        }
    }
    
    return midPoint;
}

int main() {
    int32_t inputValuePosition = 0;
    
    try {
        std::ifstream input("input.txt");

        std::vector<int32_t> inputVector;

        int32_t fstreamBuffer = 0;
        while (input >> fstreamBuffer) {
            inputVector.push_back(fstreamBuffer);
        }

        int32_t inputValue;
        std::cin >> inputValue;

        inputValuePosition = binarySearch(inputValue, inputVector, inputVector.size());
    } catch (std::invalid_argument &exc) {
        std::cerr << exc.what() << std::endl;
    }

    std::cout << inputValuePosition << std::endl;

    return 0;
}