#include <bits/stdc++.h>
using namespace std;

// Recursion
long long solve(int i, int j, vector<vector<int>> &matrix, int n, int m)
{

    if (j < 0 || j >= m)
        return INT_MAX;
    if (i == 0)
        return matrix[i][j];
    long long up = matrix[i][j] + solve(i - 1, j, matrix, n, m);
    long long leftd = matrix[i][j] + solve(i - 1, j - 1, matrix, n, m);
    long long rightd = matrix[i][j] + solve(i - 1, j + 1, matrix, n, m);

    return min(up, min(leftd, rightd));
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    long long ans = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        ans = min(ans, solve(n - 1, j, matrix, n, m));
    }
    return ans;
}

// Recursion + Memoization
long long solve(int i, int j, vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp)
{

    if (j < 0 || j >= m)
        return INT_MAX;
    if (i == 0)
        return matrix[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    long long up = matrix[i][j] + solve(i - 1, j, matrix, n, m);
    long long leftd = matrix[i][j] + solve(i - 1, j - 1, matrix, n, m);
    long long rightd = matrix[i][j] + solve(i - 1, j + 1, matrix, n, m);

    return dp[i][j] = min(up, min(leftd, rightd));
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    long long ans = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        ans = min(ans, solve(n - 1, j, matrix, n, m, dp));
    }
    return ans;
}

// Tabulation

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];
            int ld = INT_MAX;
            if (j > 0)
                ld = matrix[i][j] + dp[i - 1][j - 1];
            int rd = INT_MAX;
            if (j < n - 1)
                rd = matrix[i][j] + dp[i - 1][j + 1];
            dp[i][j] = min(up, min(ld, rd));
        }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

int main()
{
    vector<vector<int>> a = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << minFallingPathSum(a) << endl;
    return 0;
}