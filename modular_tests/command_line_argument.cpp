#include <iostream>

const uint8_t COMMAND_LINE_ARGUMENT_INDEX = 1;

int main(int argc, char *argv[])
{
    uint32_t argument = *argv[1];
    if (NULL != argument)
    {
        std::cout << argument << std::endl;
    }

    return 0;
}
