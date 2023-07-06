#include <bits/stdc++.h>
using namespace std;
long solve(int index, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (cap == 0)
        return 0;
    if (index == prices.size())
        return 0;
    if (dp[index][buy][cap] != -1)
        return dp[index][buy][cap];

    long profit = 0;
    if (buy == 1)
    {
        int yes = -prices[index] + solve(index + 1, 0, cap, prices, dp);
        int no = solve(index + 1, 1, cap, prices, dp);
        profit = max(yes, no);
    }
    else
    {
        int yes = prices[index] + solve(index + 1, 1, cap - 1, prices, dp);
        int no = solve(index + 1, 0, cap, prices, dp);
        profit = max(yes, no);
    }
    return dp[index][buy][cap] = profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(0, 1, 2, prices, dp);
}

// TABULATION

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                long profit = 0;
                if (buy == 1)
                {
                    int yes = -prices[i] + dp[i + 1][0][cap];
                    int no = dp[i + 1][1][cap];
                    profit = max(yes, no);
                }
                else
                {
                    int yes = prices[i] + dp[i + 1][1][cap - 1];
                    int no = dp[i + 1][0][cap];
                    profit = max(yes, no);
                }
                dp[i][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2];
}

// SPACE OPTIMISATION

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                long profit = 0;
                if (buy == 1)
                {
                    int yes = -prices[i] + prev[0][cap];
                    int no = prev[1][cap];
                    profit = max(yes, no);
                }
                else
                {
                    int yes = prices[i] + prev[1][cap - 1];
                    int no = prev[0][cap];
                    profit = max(yes, no);
                }
                curr[buy][cap] = profit;
            }
        }
        prev = curr;
    }
    return prev[1][2];
}

// ANOTHER SOLUTION
// Memoization -
int f(int ind, int ts, int n, vector<int> &prices, vector<vector<int>> &dp)
{
    // base cases
    if (ind == n || ts == 4)
        return 0;
    if (dp[ind][ts] != -1)
        return dp[ind][ts];
    if (ts % 2 == 0)
    {
        return dp[ind][ts] = max(-prices[ind] + f(ind + 1, ts + 1, n, prices, dp), f(ind + 1, ts, n, prices, dp));
    }
    else
    {
        return dp[ind][ts] = max(prices[ind] + f(ind + 1, ts + 1, n, prices, dp), f(ind + 1, ts, n, prices, dp));
    }
}

int maxProfit(vector<int> &prices, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(0, 0, n, prices, dp);
}
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --Tabulation-- -- -int maxProfit(vector<int> &prices, int n)

// TABULATION
int maxProfit(vector<int> &prices, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(5, -1));
    for (int i = 0; i <= 4; i++)
    {
        dp[n][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][4] = 0;
    }
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int ts = 3; ts >= 0; ts--)
        {
            if (ts % 2 == 0)
            {
                dp[ind][ts] = max(-prices[ind] + dp[ind + 1][ts + 1], dp[ind + 1][ts]);
            }
            else
            {
                dp[ind][ts] = max(prices[ind] + dp[ind + 1][ts + 1], dp[ind + 1][ts]);
            }
        }
    }
    return dp[0][0];
}
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -1 - D Space Optimisation-- -- -- -int maxProfit(vector<int> &prices, int n)

// space optimisation
int maxProfit(vector<int> &prices, int n)
{

    // Write your code here.
    vector<int> ahead(5, -1), cur(5, -1);
    for (int i = 0; i <= 4; i++)
    {
        ahead[i] = 0;
    }
    cur[4] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int ts = 3; ts >= 0; ts--)
        {
            if (ts % 2 == 0)
            {
                cur[ts] = max(-prices[ind] + ahead[ts + 1], ahead[ts]);
            }
            else
            {
                cur[ts] = max(prices[ind] + ahead[ts + 1], ahead[ts]);
            }
        }
        ahead = cur;
    }
    return ahead[0];
}
int main()
{

    return 0;
}