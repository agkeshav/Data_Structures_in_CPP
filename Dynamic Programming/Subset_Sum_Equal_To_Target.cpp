#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0
// Recursion
bool solve(int index, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (index == 0)
    {
        return (arr[0] == target);
    }
    bool notPick = solve(index - 1, target, arr);
    bool pick = false;
    if (target >= arr[index])
    {
        pick = solve(index - 1, target - arr[index], arr);
    }
    return pick || notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    return solve(n - 1, k, arr);
}

// Recursion + Memoization
bool solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == 0)
    {
        return (arr[0] == target);
    }
    if (dp[index][target] != -1)
        return dp[index][target];

    bool notPick = solve(index - 1, target, arr, dp);
    bool pick = false;
    if (target >= arr[index])
    {
        pick = solve(index - 1, target - arr[index], arr, dp);
    }
    return dp[index][target] = pick || notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}

// Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool notPick = dp[i - 1][j];
            bool pick = false;
            if (j >= arr[i])
            {
                pick = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = pick || notPick;
        }
    }
    return dp[n - 1][k];
}
int main()
{

    return 0;
}