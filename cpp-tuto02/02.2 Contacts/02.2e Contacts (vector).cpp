// Exercice 02.2e : Gestionnaire de contacts
// Crée une classe `Contact` (nom, prénom, téléphone) et une classe `Carnet` qui stocke un tableau dynamique de contacts.
// Implémente ajout, suppression, recherche par nom. Travaille les constructeurs/destructeurs et l'allocation dynamique.
// LL - à voir plus tard

#include <iostream>
#include <string>
#include <vector>

class Contact
{
private:
    std::string m_Nom;
    std::string m_Prenom;
    std::string m_Telephone;
public:
    // Constructeur
    Contact(std::string nom, std::string prenom, std::string telephone)
        : m_Nom(nom), m_Prenom(prenom), m_Telephone(telephone)
    {
    }
    // Autres méthodes
    bool is_contact(std::string chaine)
    {
        return ((m_Nom == chaine) || (m_Prenom == chaine) || (m_Telephone == chaine));
    }

    std::string affiche()
    {
        return m_Nom + ", " + m_Prenom + ", " + m_Telephone;
    }
};

class Carnet
{
private:
    std::vector<Contact> m_Contacts;
public:
    // Autres méthodes
    std::string affiche()
    {
        return "Carnet";
    }

    void ajout(std::string nom, std::string prenom, std::string telephone)
    {
        m_Contacts.push_back({ nom, prenom, telephone });
    }

    void suppression(int index)
    {
        m_Contacts.erase(m_Contacts.begin() + index);
    }

    int recherche(std::string chaine)
    {
        for (int i = 0; i < m_Contacts.size(); i++)
        {
            if (m_Contacts[i].is_contact(chaine)) return i;
        }
        return -1;
    }
};

int main()
{
    std::cout << "-- Exercice 02.2e : Gestionnaire de contacts (vector) --" << std::endl;
    Carnet monCarnet;
    monCarnet.ajout("Dupont", "Jean", "05 43 12 65 78");
}

