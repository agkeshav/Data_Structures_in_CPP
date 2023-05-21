#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &sudoku, int val)
{
    for (int i = 0; i < sudoku.size(); i++)
    {
        // Row check
        if (sudoku[row][i] == val)
        {
            return false;
        }
        // Col check
        if (sudoku[i][col] == val)
        {
            return false;
        }

        // 3*3 matrix check

        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }

    return true;
}
bool solve(vector<vector<int>> &sudoku)
{
    int n = sudoku.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Cell empty
            if (sudoku[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(i, j, sudoku, val))
                    {
                        sudoku[i][j] = val;
                        bool aageSolutionPossible = solve(sudoku);
                        if (aageSolutionPossible)
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}
int main()
{

    return 0;
}