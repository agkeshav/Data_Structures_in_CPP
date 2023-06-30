#include <bits/stdc++.h>
using namespace std;
// RECURSION
int solve(int index, int target, vector<int> &num)
{
    if (index == 0)
    {
        if (target % num[0] == 0)
            return (target / num[0]);
        else
            return 1e9;
    }
    if (target <= 0)
        return 0;
    int notTake = 0 + solve(index - 1, target, num);
    int take = 1e9;
    if (num[index] <= target)
    {
        take = 1 + solve(index, target - num[index], num);
    }
    return min(take, notTake);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int ans = solve(num.size() - 1, x, num);
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

// MEMOIZATION
int solve(int index, int target, vector<int> &num, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target % num[0] == 0)
            return (target / num[0]);
        else
            return 1e9;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notTake = 0 + solve(index - 1, target, num, dp);
    int take = 1e9;
    if (num[index] <= target)
    {
        take = 1 + solve(index, target - num[index], num, dp);
    }
    return dp[index][target] = min(take, notTake);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int ans = solve(n - 1, x, num, dp);
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

// TABULATION
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            dp[0][i] = i / num[0];
        else
            dp[0][i] = 1e9;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            int notTake = 0 + dp[i - 1][j];
            int take = 1e9;
            if (num[i] <= j)
            {
                take = 1 + dp[i][j - num[i]];
            }
            dp[i][j] = min(take, notTake);
        }
    }
    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

int main()
{

    return 0;
}