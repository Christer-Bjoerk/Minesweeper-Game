#include "Minesweeper.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <string>
#include <chrono>

// Constructor
Minesweeper::Minesweeper(int columns_get, int rows_get, int bomb_count_get) :
    rows{ rows_get }, columns{ columns_get }, maxSize{ rows * columns }, mineCount{ bomb_count_get }
{
    //Initialize the variables then run the functions below in order.

    // Create table;
    CreateTable(); 

    // Add bombs
    AddBombs();

    // Add Numbers;
    AddNumbers(); 

    // Show table;
    ShowTable(); 
}

// Destructor
Minesweeper::~Minesweeper()
{

}

void Minesweeper::CreateTable() {
    table.resize(rows, std::vector<int>(columns, 0)); // resize the table by the given values of "row" and "column"
}

void Minesweeper::AddBombs() {

    // Assume rows = 20 columns = 10
    // so max_size = rows*columns
    // max_size = 200 in this case
    // Create a vector of integers called 'mines' [1,2,3,4,5....,199,200]
    for (int i{ 1 }; i <= maxSize; ++i) {
        mines.push_back(i);
    }

    // Feed the shuffle function by the system clock
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Because we want random bombs, we need to shuffle
    // shuffle bombs vector [1,2,3,4,5....,199,200]
    // e.g. output [20,32,50,120,153,.....1,12]
    shuffle(mines.begin(), mines.end(), std::default_random_engine(seed));

    // User asks 3 bombs to be generated for example
    // mineCount = 3
    // then the expected output of mines: [20,32,50]
    // now we have 3 mines at the 20th, 32nd and 50th squares
    mines.reserve(mineCount);
    mines.resize(mineCount);

}

int Minesweeper::FindColumn(int a) 
{
    // Calculate the column by the given square number.
    int columnOfIt{ 0 };

    if (a % columns == 0) 
    {
        columnOfIt = columns;
    }
    else 
    {
        columnOfIt = a % columns;
    }

    return columnOfIt;
}

int Minesweeper::FindRow(int a, int column) 
{
    // Calculate the row by the given square number and the column
    // We have to find_column in order to find_row

    int rowOfIt{ ((a - column) / columns) + 1 };
    return rowOfIt;
}

void Minesweeper::AddNumbers() 
{
    // Add numbers
    int columnOfTheMineReal{};
    int rowOfTheMineReal{};

    // For array starting at 0
    int columnOfTheMine{};
    // For array starting at 0
    int rowOfTheMine{}; 

    for (auto bomb : mines) 
    {
        // For each of the bombs

        // Find the column of the bomb
        columnOfTheMineReal = FindColumn(bomb);

        // Find the row of the bomb
        rowOfTheMineReal = FindRow(bomb, columnOfTheMineReal);

        // For array starting at 0
        columnOfTheMine = columnOfTheMineReal - 1;

        // For array starting at 0
        rowOfTheMine = rowOfTheMineReal - 1; 

        // Add the numbers around each bomb
        // if statements are checking for the edges of the table
        // the areas around one bomb look like this:
        //   1 2 3
        //   4 * 5 
        //   6 7 8

        // For area "1"
        if (rowOfTheMine != 0 && columnOfTheMine != 0) // Check for edge
            table[rowOfTheMine - 1][columnOfTheMine - 1] += 1;

        // For area "2"
        if (rowOfTheMine != 0) // Check for edge
            table[rowOfTheMine - 1][columnOfTheMine] += 1;

        // For area "3"
        if (rowOfTheMine != 0 && columnOfTheMine != columns - 1) // Check for edge
            table[rowOfTheMine - 1][columnOfTheMine + 1] += 1;

        // For area "4"
        if (columnOfTheMine != 0) // Check for edge
            table[rowOfTheMine][columnOfTheMine - 1] += 1;

        // For area "5"
        if (columnOfTheMine != columns - 1) // Check for edge
            table[rowOfTheMine][columnOfTheMine + 1] += 1;

        // For area "6"
        if (rowOfTheMine != rows - 1 && columnOfTheMine != 0) // Check for edge
            table[rowOfTheMine + 1][columnOfTheMine - 1] += 1;

        // For area "7"
        if (rowOfTheMine != rows - 1) // Check for edge
            table[rowOfTheMine + 1][columnOfTheMine] += 1;

        // For area "8"
        if (rowOfTheMine != rows - 1 && columnOfTheMine != columns - 1) //check for edge
            table[rowOfTheMine + 1][columnOfTheMine + 1] += 1;

    }
}

void Minesweeper::ShowTable() 
{
    // Print the 2D vector table

    int squareOfTheMine{ 0 };

    for (int r = 1; r <= rows; r++) 
    {
        for (int c = 1; c <= columns; c++) 
        {
            // Find the square of the bomb formula (by given row and column)
            squareOfTheMine = ((r - 1) * columns) + c; 
            if (find(mines.begin(), mines.end(), squareOfTheMine) != mines.end()) 
            {
                // If the square is bomb, print M
                std::cout << "M";
            }
            else if (table[r - 1][c - 1] == 0) 
            {
                // If the square is empty, print "."
                std::cout << ".";
            }
            else 
            {
                // If the square is number, print number
                std::cout << table[r - 1][c - 1] << "";
            }
        }
        std::cout << std::endl;
    }
}