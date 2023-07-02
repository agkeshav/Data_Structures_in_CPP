#include <bits/stdc++.h>
using namespace std;
// RECURSION
int solve(int index, vector<int> &price, int length)
{
    if (index == 0)
    {
        if (length >= 1)
        {
            return price[0] * length;
        }
        else
        {
            return 0;
        }
    }
    int notTake = 0 + solve(index - 1, price, length);
    int take = -1e9;
    if (length >= index + 1)
        take = price[index] + solve(index, price, length - index - 1);
    return max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    return solve(n - 1, price, n);
}

// RECURSION + MEMOIZATION
int solve(int index, vector<int> &price, int length, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (length >= 1)
        {
            return price[0] * length;
        }
        else
        {
            return 0;
        }
    }
    if (length == 0)
        return 0;
    if (dp[index][length] != -1)
        return dp[index][length];
    int notTake = 0 + solve(index - 1, price, length, dp);
    int take = -1e9;
    if (length >= index + 1)
        take = price[index] + solve(index, price, length - index - 1, dp);
    return dp[index][length] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(n - 1, price, n, dp);
}

// TABULATION
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        if (i >= 1)
            dp[0][i] = price[0] * i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notTake = 0 + dp[i - 1][j];
            int take = -1e9;
            if (j >= i + 1)
                take = price[i] + dp[i][j - i - 1];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}

// SPACE OPTMISED

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (i >= 1)
            prev[i] = price[0] * i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notTake = 0 + prev[j];
            int take = -1e9;
            if (j >= i + 1)
                take = price[i] + curr[j - i - 1];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[n];
}

// 1D Array space optimised

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (i >= 1)
            prev[i] = price[0] * i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notTake = 0 + prev[j];
            int take = -1e9;
            if (j >= i + 1)
                take = price[i] + prev[j - i - 1];
            prev[j] = max(take, notTake);
        }
    }
    return prev[n];
}
int main()
{

    return 0;
}