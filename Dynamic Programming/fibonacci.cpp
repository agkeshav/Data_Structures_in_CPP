#include <bits/stdc++.h>
using namespace std;
// Recursion to memoization
int f(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

// Recursion to tabulization

int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1, -1);
    // cout << f(n, dp);

    // Tabulization
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;

    // Space optimistation
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    cout << prev << endl;

    return 0;
}