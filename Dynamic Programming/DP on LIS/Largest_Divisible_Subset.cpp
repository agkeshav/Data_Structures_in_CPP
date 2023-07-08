#include <bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1), backtrack(n);
    int maxi = INT_MIN;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        backtrack[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] % arr[j] == 0)
            {
                if (1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    backtrack[i] = j;
                }
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            last = i;
        }
    }
    vector<int> ans;
    while (backtrack[last] != last)
    {
        ans.push_back(arr[last]);
        last = backtrack[last];
    }
    ans.push_back(arr[last]);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}