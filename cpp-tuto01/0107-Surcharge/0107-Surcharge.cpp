#include <iostream>

int   addition(int a, int b);
float addition(float a, float b);

int main()
{
    std::cout << "*** Surcharge ***" << std::endl;

    std::cout << "Resultat : " << addition(3, 4) << std::endl << std::endl;
    std::cout << "Resultat : " << addition(5.5f, 10.0f) << std::endl << std::endl;

    std::cout << "*** Fin ***" << std::endl;
}

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
