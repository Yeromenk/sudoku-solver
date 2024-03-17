#include "sudoku.h"
#include <iostream>
#include <fstream>

using namespace std;


Sudoku::Sudoku()
{
    
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            grid[i][j] = 0;
        }
    }
}

bool Sudoku::loadFromFile(const char* filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        return false;
    }

    char c;
    int row = 0;
    int col = 0;

    while (file.get(c))
    {
        if (c >= '0' && c <= '9')
        {
            grid[row][col] = c - '0'; 
            col++;

            if (col == 9)
            {
                col = 0;
                row++;
                if (row == 9)
                {
                    break; 
                }
            }
        }
    }

    file.close();
    return true;
}


bool Sudoku::isSafe(int row, int col, int num)
{
    
    for (int i = 0; i < 9; ++i)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }

   
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; ++i)
    {
        for (int j = startCol; j < startCol + 3; ++j)
        {
            if (grid[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;  
}

bool Sudoku::isEmptyLocation(int& row, int& col)
{
    for (row = 0; row < 9; ++row)
    {
        for (col = 0; col < 9; ++col)
        {
            if (grid[row][col] == 0)
            {
                return true;  
            }
        }
    }
    return false;  
}


bool Sudoku::solve()
{
    int row, col;

    if (!isEmptyLocation(row, col))
    {
        
        return true;
    }

   
    for (int num = 1; num <= 9; ++num)
    {
        if (isSafe(row, col, num))
        {
            grid[row][col] = num;

            if (solve())
            {
                return true;
            }

           
            grid[row][col] = 0;
        }
    }

    return false;
}

void Sudoku::print() const
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
