#include <iostream>

int main()
{
    int hitpoints = 10;
    int damage = 0;
    bool dead = false;

    std::cout << "Hitpoints : " << hitpoints;

    std::cout << "\nDamages : ";
    std::cin >> damage;

    dead = (damage > hitpoints);

    if (dead)
    {
        std::cout << "You are dead!";
    }
    else
    {
        std::cout << "You survived!";
    }

    std::cout << "\nVersion inline : ";

    std::cout << "You are " << (dead ? "dead!\n" : "alive!\n");

    return 0;
}
