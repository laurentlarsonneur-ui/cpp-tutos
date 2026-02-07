#pragma once
#include <string>

struct Player
{
    // Déclaration des constructeurs avec surcharge

    // constructeur par défaut
    Player();

    // constructeur de copie
    Player(const Player& player);

    // constructeur standard
    Player(const std::string& name, int hitPoints, int damage, int bonus);

    // Déclaration du destructeur
    ~Player();

    std::string m_Name;
    int  m_HitPoints;
    int  m_Damages;
    int  m_Bonus;
    int* m_Data;

    bool IsDead();
    void Attack(Player& other);
};