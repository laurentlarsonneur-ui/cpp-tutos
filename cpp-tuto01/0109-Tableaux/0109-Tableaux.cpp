// Inspiré de la Playlist Youtube "Apprendre le C++ #1" par Aredhele
// Tutoriel - Apprendre le C++ #6 - Les tableaux
// https://www.youtube.com/watch?v=7A0iFhNZyEg

#include <iostream>

void compute_table(int table, int output[10])
{
    for (int i = 0; i < 10; ++i)
    {
        output[i] = (i + 1) * table;
    }
}

void affiche_table(int input[10])
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Valeur " << i + 1 << " = " << input[i] << std::endl;
    }
}


int main()
{
    int tableau[10];

    std::cout << "*** Tableau ***" << std::endl;
    compute_table(5, tableau);
    affiche_table(tableau);

    std::cout << "*** Fin ***" << std::endl;
}