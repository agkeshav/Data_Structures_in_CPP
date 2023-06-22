#include <bits/stdc++.h>
using namespace std;
// Recursion + Memoization
int solve(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0)
        return nums[index];
    if (index < 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    int pick = nums[index] + solve(index - 2, nums, dp);
    int notpick = 0 + solve(index - 1, nums, dp);

    return dp[index] = max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return solve(nums.size() - 1, nums, dp);
}

// Tabulation
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick = nums[i] + dp[i - 2];
        int notpick = 0 + dp[i - 1];

        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}

// Space optimisation--> Space O(1)
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int a = nums[0];
    int b = max(nums[1], nums[0]);
    for (int i = 2; i < n; i++)
    {
        int pick = nums[i] + a;
        int notpick = 0 + b;
        int curri = max(pick, notpick);
        a = b;
        b = curri;
    }
    return b;
}

int main()
{

    return 0;
}