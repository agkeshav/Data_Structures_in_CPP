#include <bits/stdc++.h>
using namespace std;
vector<int> lengthOfLIS(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1);
    int last = 1;
    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && 1 + dp[j] > dp[i])
            {

                dp[i] = 1 + dp[j];
            }
        }
    }
    return dp;
}
int longestBitonicSequence(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> v1 = lengthOfLIS(arr);
    reverse(arr.begin(), arr.end());
    vector<int> v2 = lengthOfLIS(arr);
    reverse(v2.begin(), v2.end());
    int maxi = INT_MIN;
    for (int i = 0; i < v1.size(); i++)
    {
        maxi = max(maxi, v1[i] + v2[i] - 1);
    }
    return maxi;
}
int main()
{

    return 0;
}