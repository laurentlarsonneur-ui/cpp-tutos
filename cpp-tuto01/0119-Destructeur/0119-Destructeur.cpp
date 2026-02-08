// Inspiré de la Playlist Youtube "Apprendre le C++ #2" par Aredhele
// Tutoriel - Apprendre le C++ #13 - Le destructeur
// https://www.youtube.com/watch?v=6mxMtGy4nAs

#include <iostream>
#include <string>

#include "Player.hpp"

int main()
{
    std::cout << "*** Destructeur ***\n";

    {
        Player player0; // Construction par défaut
    } // Appel automatique du destructeur à l'accolade fermante

    Player player1("John", 15, 5, 1);
    Player player2("Paul", 15, 5, 1);
    Player player3("George", 12, 6, 1);

    std::cout << player1.m_Name << "\n";

    player1.Attack(player2);
    std::cout << player2.m_HitPoints << "\n";

    if (player2.IsDead())
    {
        std::cout << "Player 2 is dead\n";
    }
    std::cout << player3.m_HitPoints << "\n";

    std::cout << "*** Fin ***\n";
}
