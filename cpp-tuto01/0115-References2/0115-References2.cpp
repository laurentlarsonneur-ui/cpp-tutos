// Inspiré de la Playlist Youtube "Apprendre le C++ #1" par Aredhele
// Tutoriel - Apprendre le C++ #9 - Les références
// https://www.youtube.com/watch?v=mWMhkIun1M0

#include <iostream>

// Il faut bien comprendre la difference entre des retours de fonction
// par pointeur et par référence

int* ptrfunc()
{
    // Fonction renvoyant un pointeur
    // En cas d'échec on peut renvoyer nullptr
    return nullptr;
}

int& reffunc()
{
    // Fonction renvoyant une reference
    // En cas d'échec on ne peut rien renvoyer
    // Il faut donc passer par une exception
    throw std::runtime_error("Not found")
}

int main()
{
    std::cout << "*** References2 ***\n";
    
    // On declare un entier
    int a = 5;

    // On declare une reference sur cet entier
    // C'est une L-Value reference (car il existe un autre type)
    int& b = a;

    if (!ptrfunc())
    {
        std::cout << "Not found\n";
    }

    try
    {
        reffunc();
    }
    catch (const exception& e)
    {
        // traitement de l'exception
    }
        

    std::cout << "*** Fin ***\n";
}