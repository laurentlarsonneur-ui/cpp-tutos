// Inspiré de la Playlist Youtube "Apprendre le C++ #1" par Aredhele
// Tutoriel - Apprendre le C++ #8 - Allocation Dynamique
// https://www.youtube.com/watch?v=Bw0XL4qsFec

#include <iostream>

void displayArray(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << std::endl;
    }

}

int main()
{
    std::cout << "*** Allocation ***" << std::endl;
    int number = 0;
    std::cout << "Entrez un nombre : ";
    std::cin >> number;
    std::cin.ignore();

    int* array = new int[number]; // Allocation dynamique

    for (int i = 0; i < number; ++i)
    {
        array[i] = i;
    }

    displayArray(array, number);

    delete[] array; // Libération de la mémoire

    std::cout << "*** Fin ***" << std::endl;
    std::cin.ignore();

    return 0;
}
