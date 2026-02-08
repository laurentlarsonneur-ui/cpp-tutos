// Inspiré de la Playlist Youtube "Apprendre le C++ #1" par Aredhele
// Tutoriel - Apprendre le C++ #9 - Les références
// https://www.youtube.com/watch?v=mWMhkIun1M0

#include <iostream>

void main()
{
    std::cout << "*** Const ***\n";

    // On declare un entier constant qui vaut 5
    int const a = 5;
    // const s'applique à l'élément qui se trouve à sa gauche

    // On declare un entier constant qui vaut 6
    const int b = 6;
    // quand const se trouve tout à gauche il s'applique à l'élément à sa droite

    // On declare un pointeur sur un entier
    int* ptr1 = nullptr;

    // On declare un pointeur constant sur un entier
    int* const ptr2 = nullptr;

    // On declare un pointeur sur un entier constant
    int const* ptr3 = nullptr;
    // Ecriture équivalente (à privilégier)
    const int* ptr4 = nullptr;

    // On declare un pointeur constant sur un entier constant
    int const* const ptr5 = nullptr;
    // Ecriture équivalente (à privilégier)
    const int* const ptr6 = nullptr;

    std::cout << "*** Fin ***\n";
}