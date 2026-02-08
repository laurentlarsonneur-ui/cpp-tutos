#include "Player.hpp"

// Implementation des constructeurs

// constructeur par défaut
Player::Player()
    : m_Name("")
    , m_HitPoints(0)
    , m_Damages(0)
{
    // pas besoin de code ici
}

// constructeur de copie
Player::Player(const Player& player)
    : m_Name(player.m_Name)
    , m_HitPoints(player.m_HitPoints)
    , m_Damages(player.m_Damages)
{
    // pas besoin de code ici
}

// constructeur standard
Player::Player(const std::string& name, int hitPoints, int damage)
    : m_Name(name)
    , m_HitPoints(hitPoints)
    , m_Damages(damage)
{
    // pas besoin de code ici
}

// Implémentation du destructeur
Player::~Player()
{
    // pas besoin de code ici
}

// Implémentation des méthodes de type accesseurs / getters
const std::string& Player::GetName() const
{
    return m_Name;
}

int Player::GetHitPoints() const
{
    return m_HitPoints;
}

int Player::GetDamages() const
{
    return m_Damages;
}

// Implémentation des méthodes de type modifieurs / setters
void Player::SetName(std::string& name)
{
    m_Name = name;
}

void Player::SetHitPoints(int hitPoints)
{
    m_HitPoints = hitPoints;
}

void Player::SetDamages(int damage)
{
    m_Damages = damage;
}

// Autres méthodes
bool Player::IsDead()
{
    return m_HitPoints <= 0;
}

void Player::Attack(Player& other)
{
    other.m_HitPoints -= m_Damages;
}
