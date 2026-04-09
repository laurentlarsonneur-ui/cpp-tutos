// Exercice 02.2b Tableau dynamique
// Crée un tableau dynamique d'entiers, reposant sur les tableaux "classiques" du C.
// Implémente les fonctions ajout, suppression, recherche avec allocation dynamique.
// Met en place un système de doublement de capacité en cas de débordement.
// LL - 25.03.2026

#include <iostream>

int menu();
void ajout();
void augmente_capacite();
void affiche();
int recherche();
void supprime();
void diminue_capacite();

int nb_entiers = 0;
int taille_max = 0;
int* tableau = nullptr;

void main()
{
    int choix = 0;

    std::cout << "-- Exercice 02.2b Tableau dynamique --" << std::endl;
    do
    {
        choix = menu();
        switch (choix)
        {
        case 0:
            break; // sortie
        case 1:
            ajout();
            break;
        case 2:
            affiche();
            break;
        case 3:
            recherche();
            break;
        case 4:
            supprime();
            break;
        }
    } while (choix != 0);
    delete[] tableau;
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

void ajout()
{
    int data = 0;
    std::cout << " ** Ajout **" << std::endl;
    // Ajout d'un entier au tableau
    std::cout << std::endl << " Entrez l'entier a ajouter au tableau :";
    std::cin >> data;
    
    if (nb_entiers == 0)
    {
        // Premier ajout
        tableau = new int[1];
        tableau[0] = data;
        taille_max = 1;
    }
    else
    {
        // Ajouts suivants
        if (nb_entiers >= taille_max)
        {
            augmente_capacite(); 
        }
        tableau[nb_entiers] = data;
    }
    nb_entiers += 1;
    std::cout << std::endl << " Saisie : " << data << " / Nb entiers : " << nb_entiers << " / Taille max : " << taille_max << std::endl;
    std::cout << " - - -" << std::endl;
}

void augmente_capacite()
{
    // Copie les données dans un tableau temporaire
    int* tableau_tmp = new int[taille_max * 2];
    for (int i = 0; i < taille_max; i++)
    {
        tableau_tmp[i] = tableau[i];
    }
    // Détruit et recrée le tableau global 2 fois plus grand
    delete[] tableau;
    tableau = new int[taille_max * 2];
    // Reprend les données depuis le tableau temporaire
    for (int i = 0; i < taille_max; i++)
    {
        tableau[i] = tableau_tmp[i];
    }
    delete[] tableau_tmp;
    taille_max *= 2;
}

void affiche()
{
    std::cout << " ** Affichage **" << std::endl << " ";
    if (nb_entiers == 0)
    {
        std::cout << " Tableau vide" << std::endl;
    }
    else
    {
        std::cout << " { ";
        for (int i = 0; i < nb_entiers; i++)
        {
            std::cout << tableau[i] << ' ';
        }
        std::cout << "}" << std::endl << std::endl;
    }
    std::cout << " Nb entiers : " << nb_entiers << " / Taille max : " << taille_max << std::endl;
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

    if (nb_entiers == 0)
    {
        index = 0;
    }
    else
    {
        for (int i = 0; i < nb_entiers; i++)
        {
            if (tableau[i] == data) index = i;
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
    std::cout << std::endl << " Entrez l'index de l'entier a supprimer (0 .." << (nb_entiers-1) << ") :";
    std::cin >> index;
    std::cout << std::endl << " Valeur correspondante : " << tableau[index] << std::endl;

    std::cout << std::endl << " Confirmation (o/n) :";
    std::cin >> confirm;
    if ((confirm == 'o') || (confirm == 'O'))
    {
        int* tableau_tmp = new int[taille_max];
        for (int i = 0; i < index; i++)
        {
            tableau_tmp[i] = tableau[i];
        }
        for (int i = index+1; i < nb_entiers; i++)
        {
            tableau_tmp[i-1] = tableau[i];
        }
        nb_entiers -= 1;
        for (int i = 0; i < nb_entiers; i++)
        {
            tableau[i] = tableau_tmp[i];
        }
        delete[] tableau_tmp;

        if (nb_entiers <= taille_max/2)
        {
            diminue_capacite();
        }
    }
}

void diminue_capacite()
{
    if (taille_max > 1)
    {
        taille_max /= 2;
        // Copie les données dans un tableau temporaire
        int* tableau_tmp = new int[taille_max];
        for (int i = 0; i < taille_max; i++)
        {
            tableau_tmp[i] = tableau[i];
        }
        // Détruit et recrée le tableau global 2 fois plus petit
        delete[] tableau;
        tableau = new int[taille_max];
        // Reprend les données depuis le tableau temporaire
        for (int i = 0; i < taille_max; i++)
        {
            tableau[i] = tableau_tmp[i];
        }
        delete[] tableau_tmp;
    }
}

