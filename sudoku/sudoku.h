class Sudoku {
public:
    Sudoku();

    bool loadFromFile(const char* filename); 
    bool solve();
    void print() const;

private:
    bool isSafe(int row, int col, int num);
    bool isEmptyLocation(int& row, int& col);
    int grid[9][9];
};
