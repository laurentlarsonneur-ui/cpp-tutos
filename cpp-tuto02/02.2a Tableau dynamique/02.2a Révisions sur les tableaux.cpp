// Exercice 02.2a Révisions sur les tableaux
// Rappels sur les tableaux
// LL - 20.03.2026

#include <iostream>
#include <vector>

void cree_tableau_1(int* array, int size);
void affiche_tableau_1(int* array, int size);
void cree_tableau_2(std::vector<int>& array, int size);
void affiche_tableau_2(const std::vector<int>& array);

void main()
{
    int taille = 0;
    std::cout << "-- Exercice 02.2a Révisions sur les tableaux --" << std::endl;
    std::cout << std::endl << "Entrez la taille du tableau :";
    std::cin >> taille;

    // Tableaux "bruts"
    // Méthode historique héritée du langage C
    // On passe en premier argument le nom du tableau sans crochets, et c'est un pointeur
    // Il est indispensable de passer en second argument la taille du tableau
    // Il est aussi indispensable de supprimer le tableau à la fin
    int* tab1 = new int[taille];
    cree_tableau_1(tab1, taille);
    affiche_tableau_1(tab1, taille);
    delete[] tab1;

    // Tableaux C++ avec std::vector
    // Alternative moderne avec les pointeurs intelligents
    // 2 options cependant pour le passage d'argument :
    // a) Passage par référence constante(const std::vector<int>&) : Pour lire les données sans les copier(efficace).
    // b) Passage par référence(std::vector<int>&) : Pour modifier le contenu du vecteur original.
    std::vector<int> tab2 = {};
    cree_tableau_2(tab2, taille);
    affiche_tableau_2(tab2);
}

void cree_tableau_1(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = (i+1)*(i+1);
    }
}

void affiche_tableau_1(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void cree_tableau_2(std::vector<int>& array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        array.push_back((i + 1) * (i + 1));
    }
}

void affiche_tableau_2(const std::vector<int>& array)
{
    for (int i = 0; i < array.size(); ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

