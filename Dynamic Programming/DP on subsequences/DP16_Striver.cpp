#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=1

int minSubsetSumDifference(vector<int> &nums, int n)
{
    // Write your code here.

    int k = 0;
    for (int i = 0; i < nums.size(); i++)
        k += nums[i];
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][nums[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool notPick = dp[i - 1][j];
            bool pick = false;
            if (j >= nums[i])
            {
                pick = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = pick || notPick;
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= k; i++)
    {
        if (dp[n - 1][i] == true)
        {
            ans = min(ans, abs(i - (k - i)));
        }
    }
    return ans;
}

int main()
{

    return 0;
}