#pragma once
#include <vector>
#include <chrono>

class Minesweeper
{
public:
    Minesweeper(int columns_get = 5, int rows_get = 5, int bomb_count_get = 10);
    ~Minesweeper();

protected:

private:
    int rows;
    int columns;
    int maxSize;
    int mineCount;

    // Main table of the game
    std::vector<std::vector<int>> table;
    // The vector that contains mines' locations
    std::vector<int> mines; 

    int FindColumn(int);
    int FindRow(int, int);

    void CreateTable();
    void AddBombs();
    void AddNumbers();

    void ShowTable();
};

