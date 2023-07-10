#include <bits/stdc++.h>
using namespace std;
// RECURSION
int solve(int i, int j, vector<int> &cuts, int n)
{
    if (i > j)
        return 0;
    int mini = 1e9;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i, ind - 1, cuts, n) + solve(ind + 1, j, cuts, n);
        mini = min(mini, cost);
    }
    return mini;
}

int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    return solve(1, c, cuts, n);
}

// MEMOIZATION
int solve(int i, int j, vector<int> &cuts, int n, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i, ind - 1, cuts, n, dp) + solve(ind + 1, j, cuts, n, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return solve(1, c, cuts, n, dp);
}

// TABULATION

int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for (int i = 0; i <= c; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (i > j)
                dp[i][j] = 0;
        }
    }
    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;
            int mini = 1e9;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}
int main()
{

    return 0;
}