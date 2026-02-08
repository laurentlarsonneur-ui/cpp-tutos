// Inspiré de la Playlist Youtube "Apprendre le C++ #1" par Aredhele
// Tutoriel - Apprendre le C++ #7 - Les pointeurs
// https://www.youtube.com/watch?v=etD_lFvATZc

#include <iostream>

void foo(int* prm)
{
    *prm = 50;
}

int main()
{
    int   a = 123;
    float b = 456.789;

    int* p_int = nullptr;
    float* p_float = nullptr;

    std::cout << "*** Pointeurs ***" << std::endl;

    std::cout << "Valeur de a : " << a << std::endl;
    std::cout << "Valeur de b : " << b << std::endl;

    p_int = &a;
    p_float = &b;

    foo(p_int);

    std::cout << "Adresse de a : " << p_int << std::endl;
    std::cout << "Adresse de b : " << p_float << std::endl;

    std::cout << "Valeur a l'adresse de a : " << *p_int << std::endl;
    std::cout << "Valeur a l'adresse de b : " << *p_float << std::endl;

    std::cin.ignore();
    std::cout << "*** Fin ***" << std::endl;

    return 0;
}
