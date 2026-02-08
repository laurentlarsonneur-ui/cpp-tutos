// Inspiré de la Playlist Youtube "Apprendre le C++ #1" par Aredhele
// Tutoriel - Apprendre le C++ #5 - Les fonctions
// https://www.youtube.com/watch?v=kBMwQIPVQJs

#include <iostream>
#include "0108-Function.hpp"

int main()
{
    std::cout << "*** Separation ***" << std::endl;

    std::cout << "Resultat : " << addition(3, 4) << std::endl << std::endl;
    std::cout << "Resultat : " << addition(5.5f, 10.0f) << std::endl << std::endl;
    std::cin.ignore();

    std::cout << "*** Fin ***" << std::endl;
}
