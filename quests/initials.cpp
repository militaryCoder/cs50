#include <cstring>
#include <iostream>

int main()
{
    std::string inputName;
    std::getline(std::cin, inputName);

    for (uint8_t i = 0; i < inputName.size(); i++)
    {
        for (uint32_t character = 'A'; character <= 'Z'; character++)
        {
            if (character == inputName[i])
            {
                std::cout << static_cast<char>(character);
            }
        }
    }
    std::cout << std::endl;

    return 0;
}