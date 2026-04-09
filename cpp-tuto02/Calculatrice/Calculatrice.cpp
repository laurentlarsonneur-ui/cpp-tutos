// Exercice 02.1 : Calculatrice avec surcharge d'opérateurs
// Crée une classe Fraction(numérateur, dénominateur)
// avec les opérateurs + , -, *, / surchargés, et un affichage propre.
// Bonus : simplification automatique via PGCD.
// LL - 07.03.2026

#include <iostream>
#include <string>

bool divise(int nombre, int diviseur)
{
    return !(nombre % diviseur);
}

int pgcd(int a, int b)
{
    int pg{ 1 };
    int i{ 1 };
    while ((i <= a) && (i <= b))
    {
        if (divise(a, i) && divise(b, i)) pg = i;
        i++;
    }
    return pg;
}

class Fraction
{
private:
    int m_Num;
    int m_Den;
public:
    // Constructeurs
    Fraction()
        : m_Num(0), m_Den(1)
    {}

    Fraction(int nume, int deno)
    {
        int pg = pgcd(nume, deno);
        m_Num = nume / pg ;
        m_Den = deno / pg ;
    }

    // Destructeur
    ~Fraction()
    {}

    // Autres méthodes
    std::string affiche()
    {
        return std::to_string(m_Num) + " / " + std::to_string(m_Den);
    }

    Fraction operator+(const Fraction& autre) const
    {
        return Fraction(m_Num * autre.m_Den + m_Den * autre.m_Num, m_Den * autre.m_Den);
    }

    Fraction operator-(const Fraction& autre) const
    {
        return Fraction(m_Num * autre.m_Den - m_Den * autre.m_Num, m_Den * autre.m_Den);
    }

    Fraction operator*(const Fraction& autre) const
    {
        return Fraction(m_Num * autre.m_Num, m_Den * autre.m_Den);
    }

    Fraction operator/(const Fraction& autre) const
    {
        return Fraction(m_Num * autre.m_Den, m_Den * autre.m_Num);
    }
};

int main()
{
    std::cout << "-- Exercice 02.1 : Calculatrice de fractions --" << std::endl;
    Fraction frac1(3, 12);
    std::cout << "Frac1 = " << frac1.affiche() << std::endl;
    Fraction frac2(2, 8);
    std::cout << "Frac2 = " << frac2.affiche() << std::endl;
    std::cout << "Frac1 + Frac2 = " << (frac1 + frac2).affiche() << std::endl;
    std::cout << "Frac1 - Frac2 = " << (frac1 - frac2).affiche() << std::endl;
    std::cout << "Frac1 * Frac2 = " << (frac1 * frac2).affiche() << std::endl;
    std::cout << "Frac1 / Frac2 = " << (frac1 / frac2).affiche() << std::endl;

    // std::cin.get();
}
