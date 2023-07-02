#include <bits/stdc++.h>
using namespace std;
// Recursion
long long solve(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return INT_MAX;

    long long up = grid[i][j] + solve(i - 1, j, grid);
    long long left = grid[i][j] + solve(i, j - 1, grid);
    return min(up, left);
}
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    return solve(m - 1, n - 1, grid);
}

// Recursion + Memoization
long long solve(int i, int j, vector<vector<int>> &grid, vector<vector<long long>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    long long up = grid[i][j] + solve(i - 1, j, grid, dp);
    long long left = grid[i][j] + solve(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n, -1));
    return solve(m - 1, n - 1, grid, dp);
}

// Tabulation
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                long long up = INT_MAX;
                if (i > 0)
                    up = grid[i][j] + dp[i - 1][j];
                long long left = INT_MAX;
                if (j > 0)
                    left = grid[i][j] + dp[i][j - 1];
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[m - 1][n - 1];
}
int main()
{

    return 0;
}