#include <iostream>
#include <string>

struct Player
{
    // public    : visible par tout le monde
    // protected : visible par ceux qui héritent de la structure
    // private   : visible uniquement par la structure
    std::string name;
    int hitPoints;
    int Damages;

    bool IsDead()
    {
        return hitPoints <= 0;
    }

    // La fonction est déclarée dans le struct
    void Attack(Player& other);
};

// La fonction est définie en dehors du struct
// Mais en précisant l'espace de nom du struct

void Player::Attack(Player& other)
{
    other.hitPoints -= Damages;
}

int main()
{
    std::cout << "*** Structures ***\n";
    Player player1, player2, player3;
    player1.name = "John";
    player1.hitPoints = 15 ;
    player1.Damages = 5;

    std::cout << player1.name << "\n";

    player2.name = "Paul";
    player2.hitPoints = 15;
    player2.Damages = 5;

    player1.Attack(player2);
    std::cout << player2.hitPoints << "\n";

    if (player2.IsDead())
    {
        std::cout << "Player 2 is dead\n";
    }

    player3 = player1;
    player3.name = "George";
    std::cout << player3.hitPoints << "\n";

    std::cout << "*** Fin ***\n";
}
