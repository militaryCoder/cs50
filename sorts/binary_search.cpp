#include <fstream>
#include <iostream>

const uint32_t binarySearch(const int32_t value, const int32_t *array, const uint32_t min, const uint32_t max) {
    if (max <= min) {
        throw std::invalid_argument("Max point less or equal than min point");
    }

    uint32_t midPoint = (max - min) / 2;
    if (value == array[midPoint]) {
        return midPoint;
    }
    else if (value > array[midPoint]) {
        binarySearch(value, array, midPoint + 1, max);
    }
    else if (value < array[midPoint]) {
        binarySearch(value, array, min, midPoint + 1);
    }
    else {
        return midPoint;
    }
}

int main() {
    std::ifstream input("input.txt");
    int32_t *inputArray = new int32_t;

    int i = 0;
    while (input >> inputArray[i]) {
        i++;
    }

    int32_t inputValue;
    std::cin >> inputValue;

    uint32_t inputValuePosition = 0;

    try {
        inputValuePosition = binarySearch(inputValue, inputArray, 0, i + 1);
    } catch (std::invalid_argument &exc) {
        std::cerr << exc.what() << std::endl;
    }

    std::cout << inputValuePosition << std::endl;

    return 0;
}