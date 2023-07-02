#include <bits/stdc++.h>
using namespace std;
// Memoization
int solve(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int left = solve(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;
    if (index > 1)
        right = solve(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);

    return dp[index] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return solve(n - 1, heights, dp);
}

// Tabulation

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
        {
            ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(fs, ss);
    }
    return dp[n - 1];
}

// Space optimisation
int frogJump(int n, vector<int> &heights)
{
    int prev2 = 0;
    int prev1 = abs(heights[1] - heights[0]);
    for (int i = 2; i < n; i++)
    {
        int fs = prev1 + abs(heights[i] - heights[i - 1]);
        int ss = prev2 + abs(heights[i] - heights[i - 2]);
        int curri = min(fs, ss);
        prev2 = prev1;
        prev1 = curri;
    }
    return prev1;
}
int main()
{

    return 0;
}