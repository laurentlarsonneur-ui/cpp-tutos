#include "Player.hpp"
#include <iostream>

// Implementation des constructeurs

// constructeur par défaut
Player::Player()
    : m_Name("")
    , m_HitPoints(0)
    , m_Damages(0)
    , m_Bonus(0)
    , m_Data(nullptr)
{
    // test de leak, pour expliquer l'intérêt du destructeur
    m_Data = new int();

    // pas besoin de code ici
}

// constructeur de copie
Player::Player(const Player& player)
    : m_Name(player.m_Name)
    , m_HitPoints(player.m_HitPoints)
    , m_Damages(player.m_Damages)
    , m_Bonus(player.m_Bonus)
    , m_Data(nullptr)
{
    // pas besoin de code ici
}

// constructeur standard
Player::Player(const std::string& name, int hitPoints, int damage, int bonus)
    : m_Name(name)
    , m_HitPoints(hitPoints)
    , m_Damages(damage)
    , m_Bonus(bonus)
    , m_Data(nullptr)
{
    // pas besoin de code ici
}

// Implémentation du destructeur
Player::~Player()
{
    std::cout << "Destructeur\n";

    // code qui empèche le leak mémoire
    if (m_Data)
    {
        delete m_Data;
    }
}

bool Player::IsDead()
{
    return m_HitPoints <= 0;
}

void Player::Attack(Player& other)
{
    other.m_HitPoints -= m_Damages;
}
