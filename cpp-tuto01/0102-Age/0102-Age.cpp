// Inspiré de la Playlist Youtube "Apprendre le C++ #1" par Aredhele
// Tutoriel - Apprendre le C++ #1 - Les variables
// https://www.youtube.com/watch?v=KcwAR1eS-1k

#include <iostream>

int main()
{
    int age = 0;

    std::cout << "How old are you : ";
    std::cin >> age;

    std::cout << "You are : " << age;

    return 0;
}
