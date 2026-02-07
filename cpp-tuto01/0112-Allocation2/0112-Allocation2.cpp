#include <iostream>

void displayArray(int** array, int x, int y)
{
    int i, j = 0;
    for (i = 0; i < y; ++i)
    {
        for (j = 0; j < x; ++j)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

int main()
{
    std::cout << "*** Allocation2 ***" << std::endl;

    // Allocation dynamique d'un tableau de a x b entiers
    int a = 16;
    int b = 16;
    int i, j = 0;
    int** grid = new int* [b];
    for (i = 0; i < b; ++i)
    {
        grid[i] = new int[a];
        for (j = 0; j < a; ++j)
        {
            grid[i][j] = i * a + j;
        }
    }

    // utilisation

    displayArray(grid, a, b);

    // Libération de la mémoire
    for (int i = 0; i < b; ++i)
    {
        delete[] grid[i];
    }
    delete[] grid;

    std::cout << "*** Fin ***" << std::endl;
    std::cin.ignore();

    return 0;
}
