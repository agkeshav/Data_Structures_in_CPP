#include <bits/stdc++.h>
using namespace std;
void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    // Not in same row, col, and not in same diagonal also
    // No need to check col as we are placing only a single queen in particular queen
    int x = row;
    int y = col;

    // Check for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    // check for same diagonal now
    x = row;
    y = col;

    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }
    x = row;
    y = col;

    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }
    return true;
}
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // Base case added
    if (col == n)
    {
        addSolution(board, ans, n);
    }

    // Solve 1 case, recursion will handle others
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // If it is safe to place the queen in this row and column
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    return ans;
}
int main()
{

    return 0;
}