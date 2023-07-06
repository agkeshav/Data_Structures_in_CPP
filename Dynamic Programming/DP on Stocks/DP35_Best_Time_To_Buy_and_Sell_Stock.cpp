#include <bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int mini = prices[0];
    int profit = INT_MIN;
    for (int i = 1; i < prices.size(); i++)
    {
        profit = max(profit, prices[i] - mini);
        mini = min(mini, prices[i]);
    }
    if (profit > 0)
        return profit;
    else
        return 0;
}
int main()
{

    return 0;
}