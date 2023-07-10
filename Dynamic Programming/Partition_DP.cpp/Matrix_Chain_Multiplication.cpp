#include <bits/stdc++.h>
using namespace std;
// MEMOIZATION
int solve(int i, int j, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int k = i; k <= j - 1; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, n, dp) + solve(k + 1, j, arr, n, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(1, arr.size() - 1, arr, N, dp);
}

// TABULATION
int solve(int i, int j, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int k = i; k <= j - 1; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, n, dp) + solve(k + 1, j, arr, n, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dp[i][j] = 0;
        }
    }
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j <= N - 1; j++)
        {
            int mini = 1e9;
            for (int k = i; k <= j - 1; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}
int main()
{

    return 0;
}