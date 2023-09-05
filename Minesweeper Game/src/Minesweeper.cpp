#include "Minesweeper.h"
#include <iostream>

void Minesweeper::GenerateMineField(unsigned int width, unsigned int height, unsigned int count)
{	
	// Print out a grid 

	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			std::cout << "!";
		}

		std::cout << "\n";
	}
}
