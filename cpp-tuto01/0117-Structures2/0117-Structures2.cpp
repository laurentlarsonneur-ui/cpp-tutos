#include <iostream>
#include <string>

#include "Player.hpp"

int main()
{
    std::cout << "*** Structures2 ***\n";
    Player player1, player2, player3;
    player1.m_Name = "John";
    player1.m_HitPoints = 15;
    player1.m_Damages = 5;

    std::cout << player1.m_Name << "\n";

    player2.m_Name = "Paul";
    player2.m_HitPoints = 15;
    player2.m_Damages = 5;

    player1.Attack(player2);
    std::cout << player2.m_HitPoints << "\n";

    if (player2.IsDead())
    {
        std::cout << "Player 2 is dead\n";
    }

    player3 = player1;
    player3.m_Name = "George";
    std::cout << player3.m_HitPoints << "\n";

    std::cout << "*** Fin ***\n";
}
