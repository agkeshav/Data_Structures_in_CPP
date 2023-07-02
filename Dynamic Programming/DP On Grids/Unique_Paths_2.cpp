#include <bits/stdc++.h>
using namespace std;
// Recursion
int solve(int i, int j, vector<vector<int>> obstacleGrid)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
        return 0;

    int up = solve(i - 1, j, obstacleGrid);
    int left = solve(i, j - 1, obstacleGrid);

    return up + left;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
        return 0;
    return solve(m - 1, n - 1, obstacleGrid);
}


// Recursion + Memoization
int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> obstacleGrid)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i - 1, j, dp, obstacleGrid);
    int left = solve(i, j - 1, dp, obstacleGrid);

    return dp[i][j] = up + left;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, dp, obstacleGrid);
}

// Tabulation
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    int up = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    int left = 0;
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = left + up;
                }
            }
        }
    }
    return dp[m - 1][n - 1];
}
int main()
{

    return 0;
}