#include "Player.hpp"

// Implementation des constructeurs

// constructeur par défaut
Player::Player()
    : m_Name("")
    , m_HitPoints(0)
    , m_Damages(0)
    , m_Bonus(0)
{
    // pas besoin de code ici
}

// constructeur de copie
Player::Player(const Player& player)
    : m_Name(player.m_Name)
    , m_HitPoints(player.m_HitPoints)
    , m_Damages(player.m_Damages)
    , m_Bonus(player.m_Bonus)
{
    // pas besoin de code ici
}

// constructeur standard
Player::Player(const std::string& name, int hitPoints, int damage, int bonus)
    : m_Name(name)
    , m_HitPoints(hitPoints)
    , m_Damages(damage)
    , m_Bonus(bonus)
{
    // pas besoin de code ici
}

bool Player::IsDead()
{
    return m_HitPoints <= 0;
}

void Player::Attack(Player& other)
{
    other.m_HitPoints -= m_Damages;
}
