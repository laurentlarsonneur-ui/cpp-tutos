// Inspiré de la Playlist Youtube "Apprendre le C++ #1" par Aredhele
// Tutoriel - Apprendre le C++ #1 - Les variables
// https://www.youtube.com/watch?v=KcwAR1eS-1k

#include <iostream>

int main()
{
    int a = 0;
    int b = 0;

    std::cout << "Enter a then b : ";
    std::cin >> a >> b;

    std::cout << "a + b = " << a + b;

    return 0;
}
