// Exercice 02.2c Objet Tableau Dynamique
// Crée une classe de tableaux dynamiques d'entiers, reposant sur les tableaux "classiques" du C.
// Implémente les fonctions ajout, suppression, recherche avec allocation dynamique.
// Met en place un système de doublement de capacité en cas de débordement.
// LL - 29.03.2026

#include <iostream>

class DynTab
{
private:
    int m_nb_entiers;
    int m_taille_max;
    int* m_tableau;

    void augmente_capacite()
    {
        // Copie les données dans un tableau temporaire
        int* tableau_tmp = new int[m_taille_max * 2];
        for (int i = 0; i < m_taille_max; i++)
        {
            tableau_tmp[i] = m_tableau[i];
        }
        // Détruit et recrée le tableau global 2 fois plus grand
        delete[] m_tableau;
        m_tableau = new int[m_taille_max * 2];
        // Reprend les données depuis le tableau temporaire
        for (int i = 0; i < m_taille_max; i++)
        {
            m_tableau[i] = tableau_tmp[i];
        }
        delete[] tableau_tmp;
        m_taille_max *= 2;
    }

    void diminue_capacite()
    {
        if (m_taille_max > 1)
        {
            m_taille_max /= 2;
            // Copie les données dans un tableau temporaire
            int* tableau_tmp = new int[m_taille_max];
            for (int i = 0; i < m_taille_max; i++)
            {
                tableau_tmp[i] = m_tableau[i];
            }
            // Détruit et recrée le tableau global 2 fois plus petit
            delete[] m_tableau;
            m_tableau = new int[m_taille_max];
            // Reprend les données depuis le tableau temporaire
            for (int i = 0; i < m_taille_max; i++)
            {
                m_tableau[i] = tableau_tmp[i];
            }
            delete[] tableau_tmp;
        }
    }
    
public:
    // Constructeurs
    DynTab()
        : m_nb_entiers(0), m_taille_max(0), m_tableau(nullptr)
    {
    }

    // Destructeur
    ~DynTab()
    {
        delete[] m_tableau;
    }

    void ajout()
    {
        int data = 0;
        std::cout << " ** Ajout **" << std::endl;
        // Ajout d'un entier au tableau
        std::cout << std::endl << " Entrez l'entier a ajouter au tableau :";
        std::cin >> data;

        if (m_nb_entiers == 0)
        {
            // Premier ajout
            m_tableau = new int[1];
            m_tableau[0] = data;
            m_taille_max = 1;
        }
        else
        {
            // Ajouts suivants
            if (m_nb_entiers >= m_taille_max)
            {
                augmente_capacite();
            }
            m_tableau[m_nb_entiers] = data;
        }
        m_nb_entiers += 1;
        std::cout << std::endl << " Saisie : " << data << " / Nb entiers : " << m_nb_entiers << " / Taille max : " << m_taille_max << std::endl;
        std::cout << " - - -" << std::endl;
    }

    void affiche()
    {
        std::cout << " ** Affichage **" << std::endl << " ";
        if (m_nb_entiers == 0)
        {
            std::cout << " Tableau vide" << std::endl;
        }
        else
        {
            std::cout << " { ";
            for (int i = 0; i < m_nb_entiers; i++)
            {
                std::cout << m_tableau[i] << ' ';
            }
            std::cout << "}" << std::endl << std::endl;
        }
        std::cout << " Nb entiers : " << m_nb_entiers << " / Taille max : " << m_taille_max << std::endl;
        std::cout << " - - -" << std::endl;
    }

    int recherche()
    {
        int data = 0;
        int index = 0;
        std::cout << " ** Recherche **" << std::endl;
        // Ajout d'un entier au tableau
        std::cout << std::endl << " Entrez l'entier a chercher :";
        std::cin >> data;

        if (m_nb_entiers == 0)
        {
            index = 0;
        }
        else
        {
            for (int i = 0; i < m_nb_entiers; i++)
            {
                if (m_tableau[i] == data) index = i;
            }
        }
        std::cout << std::endl << " Premier index trouve : " << index << std::endl;
        std::cout << " - - -" << std::endl;

        return index;
    }

    void supprime()
    {
        int index = 0;
        char confirm = 'n';
        std::cout << " ** Supprime **" << std::endl;
        // Suppression d'un entier au tableau
        std::cout << std::endl << " Entrez l'index de l'entier a supprimer (0 .." << (m_nb_entiers - 1) << ") :";
        std::cin >> index;
        std::cout << std::endl << " Valeur correspondante : " << m_tableau[index] << std::endl;

        std::cout << std::endl << " Confirmation (o/n) :";
        std::cin >> confirm;
        if ((confirm == 'o') || (confirm == 'O'))
        {
            int* tableau_tmp = new int[m_taille_max];
            for (int i = 0; i < index; i++)
            {
                tableau_tmp[i] = m_tableau[i];
            }
            for (int i = index + 1; i < m_nb_entiers; i++)
            {
                tableau_tmp[i - 1] = m_tableau[i];
            }
            m_nb_entiers -= 1;
            for (int i = 0; i < m_nb_entiers; i++)
            {
                m_tableau[i] = tableau_tmp[i];
            }
            delete[] tableau_tmp;

            if (m_nb_entiers <= m_taille_max / 2)
            {
                diminue_capacite();
            }
        }
    }
};

int menu();

void main()
{
    DynTab MonTab;
    int choix = 0;

    std::cout << "-- Exercice 02.2c Objet Tableau Dynamique --" << std::endl;
    do
    {
        choix = menu();
        switch (choix)
        {
        case 0:
            break; // sortie
        case 1:
            MonTab.ajout();
            break;
        case 2:
            MonTab.affiche();
            break;
        case 3:
            MonTab.recherche();
            break;
        case 4:
            MonTab.supprime();
            break;
        }
    } while (choix != 0);
}

int menu()
{
    int choix = 0;
    std::cout << "-------------------------" << std::endl;
    std::cout << " Que voulez vous faire :" << std::endl;
    std::cout << "  1 - Ajout" << std::endl;
    std::cout << "  2 - Affichage" << std::endl;
    std::cout << "  3 - Recherche" << std::endl;
    std::cout << "  4 - Suppression" << std::endl << std::endl;
    std::cout << "  0 - Sortir" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << " Votre choix :";
    std::cin >> choix;
    std::cout << std::endl;
    return choix;
}
