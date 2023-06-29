#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// MEMOIZATION
int solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];

    int notpick = solve(index - 1, target, arr, dp) % mod;
    int pick = 0;
    if (target >= arr[index])
        pick = solve(index - 1, target - arr[index], arr, dp) % mod;

    return dp[index][target] = (notpick + pick) % mod;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int target = (sum - d) / 2;
    if ((sum - d) & 1 || (sum - d) < 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return solve(n - 1, target, arr, dp);
}





// TABULATION

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int target = (sum - d) / 2;
    if ((sum - d) & 1 || (sum - d) < 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int notpick = dp[i - 1][j] % mod;
            int pick = 0;
            if (j >= arr[i])
                pick = dp[i - 1][j - arr[i]] % mod;

            dp[i][j] = (notpick + pick) % mod;
        }
    }
    return dp[n - 1][target] % mod;
}

int main()
{

    return 0;
}