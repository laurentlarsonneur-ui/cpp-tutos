#pragma once
#include <string>

// On passe ici d'une struct (projet 0119) à une classe
// Dans une struct tous les membres sont publics
// Dans une classe tous les membres sont par défaut privés

class Player
{
    // Spécifieurs d'accès public/protected/private

public:
    // Déclaration des constructeurs avec surcharge
    Player();
    Player(const Player& player);
    Player(const std::string& name, int hitPoints, int damage);

    // Déclaration du destructeur
    ~Player();

    bool IsDead();
    void Attack(Player& other);

    // Déclaration des méthodes de type accesseurs / getters
    const std::string& GetName() const;
    int GetHitPoints() const;
    int GetDamages() const;

    // Déclaration des méthodes de type modifieurs / setters
    void SetName(std::string& name);
    void SetHitPoints(int hitPoints);
    void SetDamages(int damage);

private:
    std::string m_Name;
    int  m_HitPoints;
    int  m_Damages;
};