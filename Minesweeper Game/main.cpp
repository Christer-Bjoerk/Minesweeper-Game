#include <iostream>
#include "src/Minesweeper.h"

int main() 
{
	Minesweeper mineSweeper;

	mineSweeper.GenerateMineField(5, 5, 3);

	std::cout << "Hello World";

	return 0;
}