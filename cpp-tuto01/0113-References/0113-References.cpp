#include <iostream>

void intfonc(int prm)
{
    std::cout << " |- intfonc -" << std::endl;
    std::cout << " |prm : " << prm << std::endl;
    prm = 6;
    std::cout << " |modif : " << prm << std::endl;
}

void ptrfonc(int* prm)
{
    std::cout << " |- ptrfonc -" << std::endl;
    std::cout << " |*prm : " << *prm << std::endl;
    *prm = 7;
    std::cout << " |modif : " << *prm << std::endl;
}

void reffonc(int& prm)
{
    std::cout << " |- reffonc -" << std::endl;
    std::cout << " |prm : " << prm << std::endl;
    prm = 8;
    std::cout << " |modif : " << prm << std::endl;
}

int main()
{
    std::cout << "*** References ***" << std::endl;

    int a = 5;
    std::cout << "- initialisation -" << std::endl;
    std::cout << "a : " << a << " / sizeof(a) : " << sizeof(a) << std::endl;
    // Appel simple
    intfonc(a);
    std::cout << "- retour -" << std::endl;
    std::cout << "a : " << a << std::endl << std::endl;

    // Pointeur
    int* ptr = &a;
    std::cout << "- pointeur -" << std::endl;
    std::cout << "*ptr : " << *ptr << " / sizeof(ptr) : " << sizeof(ptr) << " / sizeof(*ptr) : " << sizeof(*ptr) << std::endl;
    // Appel pointeur
    ptrfonc(ptr);
    std::cout << "- retour -" << std::endl;
    std::cout << "a : " << a << std::endl << std::endl;

    // Reference
    int& ref = a;
    std::cout << "- reference -" << std::endl;
    std::cout << "ref : " << ref << " / sizeof(ref) : " << sizeof(ref) << std::endl;
    // Appel ref
    reffonc(ref);
    std::cout << "- retour -" << std::endl;
    std::cout << "a : " << a << std::endl << std::endl;

    std::cout << "*** Fin ***" << std::endl;

    return 0;
}