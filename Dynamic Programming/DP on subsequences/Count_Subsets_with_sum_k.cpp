#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// Recursion
int solve(int index, int n, vector<int> &arr, int k)
{
    if (k == 0)
        return 1;
    if (k < 0)
        return 0;
    if (index == 0)
    {
        if (arr[index] == k)
            return 1;
        return 0;
    }
    int notpick = solve(index - 1, n, arr, k);
    int pick = 0;
    if (k >= arr[index])
        pick = solve(index - 1, n, arr, k - arr[index]);
    return pick + notpick;
}
int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    return solve(n - 1, n, arr, k);
}

// MEMOIZATION
#define mod 1000000007;
int solve(int index, int n, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return 1;
    if (k < 0)
        return 0;
    if (index == 0)
    {
        if (arr[index] == k)
            return 1;
        return 0;
    }
    if (dp[index][k] != -1)
        return dp[index][k];
    int notpick = solve(index - 1, n, arr, k, dp) % mod;
    int pick = 0;
    if (k >= arr[index])
        pick = solve(index - 1, n, arr, k - arr[index], dp) % mod;
    return dp[index][k] = (pick + notpick) % mod;
}
int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, n, arr, k, dp) % mod;
}

// Tabulation
int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int notpick = dp[i - 1][j] % mod;
            int pick = 0;
            if (j >= arr[i])
                pick = dp[i - 1][j - arr[i]] % mod;

            dp[i][j] = (pick + notpick) % mod;
        }
    }
    return dp[n - 1][k] % mod;
}

// If the array contain zeroes as well
// MEMOIZATION
#define mod 1000000007;
int solve(int index, int n, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (k == 0 && arr[0] == 0)
            return 2;
        if (k == 0 || k == arr[0])
            return 1;
        return 0;
    }
    if (dp[index][k] != -1)
        return dp[index][k];
    int notpick = solve(index - 1, n, arr, k, dp) % mod;
    int pick = 0;
    if (k >= arr[index])
        pick = solve(index - 1, n, arr, k - arr[index], dp) % mod;
    return dp[index][k] = (pick + notpick) % mod;
}
int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, n, arr, k, dp) % mod;
}
int main()
{

    return 0;
}