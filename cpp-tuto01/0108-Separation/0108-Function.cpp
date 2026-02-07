#include <iostream>
#include "0108-Function.hpp"

int addition(int a, int b)
{
    std::cout << "-- int --" << std::endl;
    return a + b;
}

float addition(float a, float b)
{
    std::cout << "-- float --" << std::endl;
    return a + b;
}