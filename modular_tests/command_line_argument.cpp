#include <iostream>

const uint8_t COMMAND_LINE_ARGUMENT_INDEX = 1;

int main(int argc, char *argv[])
{
	if (NULL != argv[1])
	{
		std::cout << argv[1] << std::endl;
	}
	
	return 0;
}