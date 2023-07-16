#include <bits/stdc++.h>
using namespace std;
// RECURSION
int solve(int index, vector<int> &arr, int k)
{
    if (index == arr.size())
        return 0;
    int n = arr.size();
    int ans = -1e9;
    int len = 0;
    int maxi = -1e9;
    for (int j = index; j < min(n, index + k); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = len * maxi + solve(j + 1, arr, k);
        ans = max(ans, sum);
    }
    return ans;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    return solve(0, arr, k);
}

// MEMOIZATION
int solve(int index, vector<int> &arr, int k, int n, vector<int> &dp)
{
    if (index == arr.size())
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int ans = -1e9;
    int len = 0;
    int maxi = -1e9;
    for (int j = index; j < min(n, index + k); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = len * maxi + solve(j + 1, arr, k, n, dp);
        ans = max(ans, sum);
    }
    return dp[index] = ans;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(0, arr, k, n, dp);
}

// TABULATION
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        int ans = -1e9;
        int len = 0;
        int maxi = -1e9;
        for (int j = index; j < min(n, index + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + dp[j + 1];
            ans = max(ans, sum);
        }
        dp[index] = ans;
    }
    return dp[0];
}

int main()
{

    return 0;
}