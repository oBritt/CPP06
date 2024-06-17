
#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << "Wrong amount of args" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
}