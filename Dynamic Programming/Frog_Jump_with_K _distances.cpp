#include <bits/stdc++.h>
using namespace std;
// Memoization
int solve(int index, vector<int> &height, int n, int k, vector<int> &dp)
{
    if (index == 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    int mini = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (index >= j)
            mini = min(mini, solve(index - j, height, n, k, dp) + abs(height[index] - height[index - j]));
    }
    return dp[index] = mini;
}

int minimizeCost(vector<int> &height, int n, int k)
{
    // Code here
    vector<int> dp(n, -1);
    return solve(n - 1, height, n, k, dp);
}

// Tabulation

int minimizeCost(vector<int> &height, int n, int k)
{
    // Code here
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i >= j)
                mini = min(mini, dp[i - j] + abs(height[i] - height[i - j]));
        }
        dp[i] = mini;
    }

    return dp[n - 1];
}

// Space optimised

// We can at max optimised the space from O(N) to O(k).
int main()
{

    return 0;
}