#include <iostream>
#include "src/Minesweeper.h"

int main() 
{
    // Generates a mine field by giving the heigt, width and X mines.
    Minesweeper* app = new Minesweeper(10, 10, 10);

    delete app;
    std::cout << std::endl;

	return 0;
}