#include <bits/stdc++.h>
using namespace std;
// memoization
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
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return solve(0, 1, k, prices, dp);
}
// tabulation
int maxProfit(int k, vector<int> &prices)
{

    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
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
    return dp[0][1][k];
}
// space optimisation
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
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
    return prev[1][k];
}
int main()
{

    return 0;
}