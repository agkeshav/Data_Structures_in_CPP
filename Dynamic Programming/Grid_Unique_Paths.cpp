#include <bits/stdc++.h>
using namespace std;
// Recursion
int solve(int i, int j, int m, int n)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;

    int up = solve(i - 1, j, m, n);
    int left = solve(i, j - 1, m, n);
    return (left + up);
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    return solve(m - 1, n - 1, m, n);
}

// Recursion + Memoization
int solve(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i - 1, j, dp);
    int left = solve(i, j - 1, dp);

    return dp[i][j] = left + up;
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, dp);
}



// Tabulation
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
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
    return dp[m - 1][n - 1];
}


int main()
{

    return 0;
}