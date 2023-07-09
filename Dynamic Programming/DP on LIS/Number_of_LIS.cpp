#include <bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &arr)
{

    vector<int> dp(arr.size(), 1), cnt(arr.size(), 1);
    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && 1 + dp[j] > dp[i])
            {

                dp[i] = 1 + dp[j];
                cnt[i] = cnt[j];
            }
            else if (arr[j] < arr[i] && 1 + dp[j] == dp[i])
                cnt[i] += cnt[j];
        }
    }
    int maxi = *max_element(dp.begin(), dp.end());
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (dp[i] == maxi)
        {
            ans += cnt[i];
        }
    }
    return ans;
}
int main()
{

    return 0;
}