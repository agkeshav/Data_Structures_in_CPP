#include <bits/stdc++.h>
using namespace std;
// RECURSION
int solve(int index, int target, vector<int> &profit, vector<int> &weight)
{
    if (index == 0)
    {
        if (target >= weight[0])
            return (target / weight[0]) * profit[0];
        else
            return 0;
    }
    int notTake = 0 + solve(index - 1, target, profit, weight);
    int take = -1e9;
    if (weight[index] <= target)
    {
        take = profit[index] + solve(index, target - weight[index], profit, weight);
    }
    return max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    return solve(n - 1, w, profit, weight);
}

// RECURSION + MEMOIZATION
int solve(int index, int target, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target >= weight[0])
            return (target / weight[0]) * profit[0];
        else
            return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notTake = 0 + solve(index - 1, target, profit, weight, dp);
    int take = -1e9;
    if (weight[index] <= target)
    {
        take = profit[index] + solve(index, target - weight[index], profit, weight, dp);
    }
    return dp[index][target] = max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(n - 1, w, profit, weight, dp);
}

// TABULATION
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = 0; i <= w; i++)
    {
        if (i >= weight[0])
        {
            dp[0][i] = (i / weight[0]) * profit[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = 0 + dp[i - 1][j];
            int take = -1e9;
            if (weight[i] <= j)
            {
                take = profit[i] + dp[i][j - weight[i]];
            }
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}

// SPACE OPTIMISATION


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> prev(w + 1, 0), curr(w + 1, 0);
    for (int i = 0; i <= w; i++)
    {
        if (i >= weight[0])
        {
            prev[i] = (i / weight[0]) * profit[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = 0 + prev[j];
            int take = -1e9;
            if (weight[i] <= j)
            {
                take = profit[i] + curr[j - weight[i]];
            }
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[w];
}

int main()
{

    return 0;
}