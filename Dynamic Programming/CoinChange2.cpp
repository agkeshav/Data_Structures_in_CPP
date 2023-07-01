#include <bits/stdc++.h>
using namespace std;
// RECURSION
long solve(int index, int target, int *denominations)
{
    if (index == 0)
    {
        if (target % *(denominations) == 0)
            return 1;
        else
            return 0;
    }
    long notTake = solve(index - 1, target, denominations);
    long take = 0;
    if (*(denominations + index) <= target)
        take = solve(index, target - *(denominations + index), denominations);
    return take + notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    return solve(n - 1, value, denominations);
}

// RECURSION + MEMOIZATION

long solve(int index, int target, int *denominations, vector<vector<long>> &dp)
{
    if (index == 0)
    {
        if (target % *(denominations) == 0)
            return 1;
        else
            return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    long notTake = solve(index - 1, target, denominations, dp);
    long take = 0;
    if (*(denominations + index) <= target)
        take = solve(index, target - *(denominations + index), denominations, dp);
    return dp[index][target] = take + notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return solve(n - 1, value, denominations, dp);
}

// TABULTAION

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int i = 0; i <= value; i++)
    {
        if (i % *(denominations) == 0)
        {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= value; j++)
        {
            long notTake = dp[i - 1][j];
            long take = 0;
            if (*(denominations + i) <= j)
                take = dp[i][j - *(denominations + i)];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][value];
}

// space optimistaion

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<long> prev(value + 1, 0), curr(value + 1, 0);
    for (int i = 0; i <= value; i++)
    {
        if (i % *(denominations) == 0)
        {
            prev[i] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= value; j++)
        {
            long notTake = prev[j];
            long take = 0;
            if (*(denominations + i) <= j)
                take = curr[j - *(denominations + i)];
            curr[j] = take + notTake;
        }
        prev = curr;
    }
    return prev[value];
}
int main()
{

    return 0;
}