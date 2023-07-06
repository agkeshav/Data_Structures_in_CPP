#include <bits/stdc++.h>
using namespace std;
// MEMOIZATION
long solve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (index >= prices.size())
        return 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];
    if (buy == 1)
    {
        return dp[index][buy] = max(-prices[index] + solve(index + 1, 0, prices, dp), 0 + solve(index + 1, 1, prices, dp));
    }
    else
    {
        return dp[index][buy] = max(prices[index] + solve(index + 2, 1, prices, dp), 0 + solve(index + 1, 0, prices, dp));
    }
}
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return solve(0, 1, prices, dp);
}

// TABULATION
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0));
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
                int yes = prices[i] + dp[i + 2][1];
                int no = dp[i + 1][0];
                profit = max(yes, no);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

int main()
{

    return 0;
}