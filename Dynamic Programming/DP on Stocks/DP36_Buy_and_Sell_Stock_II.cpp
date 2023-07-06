#include <bits/stdc++.h>
using namespace std;
// RECURSION
long solve(int index, int buy, vector<int> &prices)
{
    if (index == prices.size())
        return 0;
    long profit = 0;
    if (buy == 1)
    {
        int yes = -prices[index] + solve(index + 1, 0, prices);
        int no = solve(index + 1, 1, prices);
        profit = max(yes, no);
    }
    else
    {
        int yes = prices[index] + solve(index + 1, 1, prices);
        int no = solve(index + 1, 0, prices);
        profit = max(yes, no);
    }
    return profit;
}
int maxProfit(vector<int> &prices)
{
    return solve(0, 1, prices);
}

// MEMOIZATION
long solve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (index == prices.size())
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];
    long profit = 0;
    if (buy == 1)
    {
        int yes = -prices[index] + solve(index + 1, 0, prices, dp);
        int no = solve(index + 1, 1, prices, dp);
        profit = max(yes, no);
    }
    else
    {
        int yes = prices[index] + solve(index + 1, 1, prices, dp);
        int no = solve(index + 1, 0, prices, dp);
        profit = max(yes, no);
    }
    return dp[index][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return solve(0, 1, prices, dp);
}

// TABULATION
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    dp[prices.size()][0] = dp[prices.size()][1] = 0;
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;
            if (buy == 1)
            {
                int yes = -prices[i] + dp[i + 1][0];
                int no = dp[i + 1][1];
                profit = max(yes, no);
            }
            else
            {
                int yes = prices[i] + dp[i + 1][1];
                int no = dp[i + 1][0];
                profit = max(yes, no);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

// SPACE OPTIMISATION
int maxProfit(vector<int> &prices)
{
    vector<int> prev(2, 0), curr(2, 0);
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;
            if (buy == 1)
            {
                int yes = -prices[i] + prev[0];
                int no = prev[1];
                profit = max(yes, no);
            }
            else
            {
                int yes = prices[i] + prev[1];
                int no = prev[0];
                profit = max(yes, no);
            }
            curr[buy] = profit;
        }
        prev = curr;
    }
    return prev[1];
}
int main()
{

    return 0;
}