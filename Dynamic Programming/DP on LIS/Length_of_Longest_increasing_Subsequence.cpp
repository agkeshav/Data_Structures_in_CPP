#include <bits/stdc++.h>
using namespace std;
// recursion
int solve(int index, int prev, int n, vector<int> &arr)
{
    if (index == n)
        return 0;
    int notTake = solve(index + 1, prev, n, arr);
    int take = -1e9;
    if (prev == -1 || arr[index] > arr[prev])
    {
        take = 1 + solve(index + 1, index, n, arr);
    }
    return max(take, notTake);
}
int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    return (int)solve(0, -1, n, arr);
}
// memoization
long solve(int index, int prev, int n, vector<int> &arr, vector<vector<long>> &dp)
{
    if (index == n)
        return 0;
    if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];
    long notTake = solve(index + 1, prev, n, arr, dp);
    long take = -1e9;
    if (prev == -1 || arr[index] > arr[prev])
    {
        take = 1 + solve(index + 1, index, n, arr, dp);
    }
    return dp[index][prev + 1] = max(take, notTake);
}
int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<long>> dp(n, vector<long>(n + 1, -1));
    return (int)solve(0, -1, n, arr, dp);
}

// tabulation
int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            long notTake = dp[ind + 1][prev + 1];
            long take = -1e9;
            if (prev == -1 || arr[ind] > arr[prev])
            {
                take = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

// Another Solution
// printing of LIS as well
int lengthOfLIS(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1), backTrack(arr.size());
    int last = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        backTrack[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && 1 + dp[j] > dp[i])
            {

                dp[i] = 1 + dp[j];
                backTrack[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            last = i;
        }
    }
    vector<int> ans;
    while (backTrack[last] != last)
    {
        ans.push_back(arr[last]);
        last = backTrack[last];
    }
    ans.push_back(arr[backTrack[last]]);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return maxi;
}

// ANOTHER SOLUTION BINARY SEARCH APPROACH
int lengthOfLIS(vector<int> &arr)
{
    // BINARY SEARCH APPROCH
    int n = arr.size();
    vector<int> temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}

int main()
{

    return 0;
}