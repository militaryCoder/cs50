#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

template<typename DataType, class DataStructure>
const uint32_t binarySearch(const DataType value, const DataStructure &structure)
{
    auto currentAccessIterator = structure.cbegin();
    
    
    // Moves iterator given it by n elements
    std::advance(currentAccessIterator,
                 structure.size() / 2);
    
    while (*currentAccessIterator != value)
    {
        const DataType accessedValue = *currentAccessIterator;

        if (value > accessedValue)
        {
            std::advance(currentAccessIterator,
                         (structure.size() - *currentAccessIterator) / 2);
        }
        else if (value < accessedValue)
        {
            currentAccessIterator = ((structure.cbegin() + 1 == currentAccessIterator) ? structure.cbegin() : currentAccessIterator / 2);
        }
    }
    
    return currentAccessIterator;
}

int main(int argc, char **argv)
{
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

        const uint32_t inputValueIndex = binarySearch(inputValue, inputVector);
        
        std::cout << inputValueIndex << std::endl;
    }
    catch (std::invalid_argument &exc)
    {
        std::cerr << exc.what() << std::endl;
    }

    return 0;
}