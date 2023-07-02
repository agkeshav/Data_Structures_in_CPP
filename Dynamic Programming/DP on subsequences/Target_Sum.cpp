#include <bits/stdc++.h>
using namespace std;
// MEMOIZATION
int solve(int idx, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (nums[0] == 0)
        {
            if (target == 0)
                return 2;
        }
        if (target == nums[0] || target == 0)
            return 1;
        return 0;
    }
    if (dp[idx][target] != -1)
        return dp[idx][target];
    int notTake = solve(idx - 1, target, nums, dp);
    int take = 0;
    if (target >= nums[idx])
    {
        take = solve(idx - 1, target - nums[idx], nums, dp);
    }
    return dp[idx][target] = take + notTake;
}
int findTargetSumWays(vector<int> &nums, int d)
{
    int sum = 0;
    for (auto it : nums)
        sum += it;
    int target = (sum - d) / 2;
    if ((sum - d) & 1 || (sum - d) < 0)
        return 0;
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    return solve(nums.size() - 1, target, nums, dp);
}
int main()
{

    return 0;
}