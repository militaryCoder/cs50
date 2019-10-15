#include <iostream>

int main()
{
    uint32_t height;
    std::cin >> height;

    for (uint32_t h = 0; h < height; h++)
    {
        const uint32_t spacesToPrintNumber = height - h;
         
        for (uint32_t s = spacesToPrintNumber; s > 0; s--)
        {
            std::cout << " ";
        }
        for (uint32_t ch = 0; ch <= h; ch++)
        {
            std::cout << "#";
        }
        std::cout << std::endl;
    }
    
    return 0;
}