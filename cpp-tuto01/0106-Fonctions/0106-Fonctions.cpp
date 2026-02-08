// Inspiré de la Playlist Youtube "Apprendre le C++ #1" par Aredhele
// Tutoriel - Apprendre le C++ #5 - Les fonctions
// https://www.youtube.com/watch?v=kBMwQIPVQJs

#include <iostream>

int pow_custom(int number, int n);

int main()
{
    std::cout << "*** Fonctions ***\n";

    std::cout << "Resultat : " << pow_custom(3, 4);
    std::cout << std::endl;

    std::cout << "*** Fin ***\n";
}

int pow_custom(int number, int n)
{
    int result = 1;
    for (int i = 0; i < n; ++i)
    {
        result *= number;
    }

    return result;
}
