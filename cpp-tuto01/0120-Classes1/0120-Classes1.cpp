#include <iostream>
#include <string>

#include "Player.hpp"

int main()
{
    std::cout << "*** Classes1 ***\n";

    Player player1("John", 15, 5);
    Player player2("Paul", 15, 5);
    Player player3("George", 12, 6);

    std::cout << player1.GetName() << "\n";

    player1.Attack(player2);
    std::cout << player2.GetHitPoints() << "\n";

    if (player2.IsDead())
    {
        std::cout << "Player 2 is dead\n";
    }
    std::cout << player3.GetHitPoints() << "\n";

    std::cout << "*** Fin ***\n";
}
