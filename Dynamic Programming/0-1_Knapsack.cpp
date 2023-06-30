#include <bits/stdc++.h>
using namespace std;
// RECURSION
int solve(int index, int maxWeight, vector<int> &weight, vector<int> &value)
{
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    if (maxWeight == 0)
        return 0;
    int notTake = 0 + solve(index - 1, maxWeight, weight, value);
    int take = -1e9;
    if (maxWeight >= weight[index])
    {
        take = value[index] + solve(index - 1, maxWeight - weight[index], weight, value);
    }
    return max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    return solve(n - 1, maxWeight, weight, value);
}

// MEMOIZATION // T.c = 0(N*maxWeight) // S.c = 0(N*maxWeight) + O(N)
int solve(int index, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    if (maxWeight == 0)
        return 0;
    if (dp[index][maxWeight] != -1)
        return dp[index][maxWeight];
    int notTake = 0 + solve(index - 1, maxWeight, weight, value, dp);
    int take = -1e9;
    if (maxWeight >= weight[index])
    {
        take = value[index] + solve(index - 1, maxWeight - weight[index], weight, value, dp);
    }
    return dp[index][maxWeight] = max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(n - 1, maxWeight, weight, value, dp);
}

// TABULATION // T.c = 0(N*maxWeight) // S.c = 0(N*maxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= maxWeight; i++)
    {
        if (weight[0] <= i)
        {
            dp[0][i] = value[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int notTake = 0 + dp[i - 1][j];
            int take = -1e9;
            if (j >= weight[i])
            {
                take = value[i] + dp[i - 1][j - weight[i]];
            }
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][maxWeight];
}

// SPACE OPTIMISATION

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
    for (int i = 1; i <= maxWeight; i++)
    {
        if (weight[0] <= i)
        {
            prev[i] = value[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int notTake = 0 + prev[j];
            int take = -1e9;
            if (j >= weight[i])
            {
                take = value[i] + prev[j - weight[i]];
            }
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[maxWeight];
}

// Only single row space used
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<int> prev(maxWeight + 1, 0);
    for (int i = 0; i <= maxWeight; i++)
    {
        if (weight[0] <= i)
        {
            prev[i] = value[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = maxWeight; j >= 0; j--)
        {
            int notTake = 0 + prev[j];
            int take = -1e9;
            if (j >= weight[i])
            {
                take = value[i] + prev[j - weight[i]];
            }
            prev[j] = max(take, notTake);
        }
    }
    return prev[maxWeight];
}
int main()
{

    return 0;
}