#include <fstream>
#include <iostream>
#include <vector>

const int32_t binarySearch(const int32_t value, const std::vector<int32_t> &vector, const size_t size) {
    if (size < 0)
    {
        throw std::invalid_argument("Given argument [size] is invalid - cannot be less than minimal treshold");
    }

    uint32_t currentAccessIndex = size / 2;
    std::cout << "Starting at position [" << currentAccessIndex << "]\n";
    
    while (vector[currentAccessIndex] != value)
    {
        const int32_t accessedValue = vector[currentAccessIndex];
        std::cout << "Accessed value [" << accessedValue << "] at index [" << currentAccessIndex << "]\n";
        if (value > accessedValue)
        {
            currentAccessIndex = currentAccessIndex + ((size - currentAccessIndex) / 2);
        }
        else if (value < accessedValue)
        {
            currentAccessIndex = currentAccessIndex - ((1 == currentAccessIndex) ? 1 : currentAccessIndex / 2);
        }
    }
    
    return currentAccessIndex;
}

int main(int argc, char **argv)
{
    int32_t inputValueIndex = 0;
    
    try
    {
        if (argc < 3)
        {
            throw std::invalid_argument("Usage: ./binary_search <path-to-source> <search-query>");
        }
        
        const std::string pathToSource = argv[1];
        const int32_t inputValue = static_cast<int32_t>(*argv[2] - '0');
        std::cout << inputValue << std::endl;

        std::ifstream input(pathToSource);

        std::vector<int32_t> inputVector;

        int32_t fstreamBuffer = 0;
        while (input >> fstreamBuffer)
        {
            inputVector.push_back(fstreamBuffer);
        }

        inputValueIndex = binarySearch(inputValue, inputVector, inputVector.size());
    }
    catch (std::invalid_argument &exc)
    {
        std::cerr << exc.what() << std::endl;
    }

    std::cout << inputValueIndex << std::endl;

    return 0;
}