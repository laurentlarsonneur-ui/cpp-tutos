// Inspiré de la Playlist Youtube "Apprendre le C++ #1" par Aredhele
// Tutoriel - Apprendre le C++ #3 - Les boucles
// https://www.youtube.com/watch?v=K6OFRcejqpw

#include <iostream>

int main()
{
    int i = 0;

    std::cout << "*** boucles ***\n";

    std::cout << "-- boucle for --";
    for (i = 1; i <= 5; i++)
    {
        std::cout << "\nEtape " << i;
    }

    std::cout << "\n-- boucle while --";
    i = 0;
    while (i < 5)
    {
        i++;
        std::cout << "\nEtape " << i;
    }

    std::cout << "\n-- boucle do/while --";
    i = 0;
    do
    {
        i++;
        std::cout << "\nEtape " << i;
    } while (i < 5);

    std::cout << "\n-- boucle while/break/continue --";
    i = 0;
    while (true)
    {
        std::cout << "\nEntrez un nombre (0 pour sortir, 1 pour recommencer) : ";
        std::cin >> i;
        if (i == 0) break;
        if (i == 1) continue;
        std::cout << "\nNombre saisi : " << i;
    }

    std::cout << "\n-- Fin --\n";
}
