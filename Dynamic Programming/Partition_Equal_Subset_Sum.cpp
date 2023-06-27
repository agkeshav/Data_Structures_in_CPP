#include <bits/stdc++.h>
using namespace std;
// Memoization
bool solve(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == 0)
    {
        return (nums[0] == target);
    }
    if (dp[index][target] != -1)
        return dp[index][target];

    bool notpick = solve(index - 1, target, nums, dp);
    bool take = false;
    if (target >= nums[index])
    {
        take = solve(index - 1, target - nums[index], nums, dp);
    }
    return dp[index][target] = (notpick) || (take);
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];
    if (sum & 1 || nums.size() == 1)
    {
        return false;
    }
    else
    {
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
        return solve(nums.size() - 1, sum / 2, nums, dp);
    }
}
int main()
{

    return 0;
}