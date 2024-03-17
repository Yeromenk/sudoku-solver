#include "sudoku.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    Sudoku sudoku;
    if (sudoku.loadFromFile("sudoku1.txt")) 
    { 
        if (sudoku.solve()) 
        {
            cout << "Solution for sudoku1.txt:\n";
            sudoku.print();
            cout << endl;
        }
        else
        {
            cout << "Sudoku dont have solution.\n";
        }
    }
    else 
    {
        cout << "Something went wrong.\n";
    }

    if (sudoku.loadFromFile("sudoku2.txt"))
    {
        if (sudoku.solve())
        {
            cout << "Solution for sudoku2.txt:\n";
            sudoku.print();
            cout << endl;
        }
        else
        {
            cout << "Sudoku dont have solution.\n";
        }
    }
    else
    {
        cout << "Something went wrong.\n";
    }

    if (sudoku.loadFromFile("sudoku3.txt"))
    {
        if (sudoku.solve())
        {
            cout << "Solution for sudoku3.txt:\n";
            sudoku.print();
            cout << endl;
        }
        else
        {
            cout << "Sudoku dont have solution.\n";
        }
    }
    else
    {
        cout << "Something went wrong.\n";
    }
    return 0;
}
