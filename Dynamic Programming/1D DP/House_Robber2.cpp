#include <bits/stdc++.h>
using namespace std;
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
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    vector<int> temp1;
    vector<int> temp2;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != nums.size() - 1)
            temp2.push_back(nums[i]);
    }
    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}
int main()
{

    return 0;
}