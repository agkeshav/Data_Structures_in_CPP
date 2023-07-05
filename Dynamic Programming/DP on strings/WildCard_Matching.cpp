#include <bits/stdc++.h>
using namespace std;
// RECURSION
int solve(string &pattern, string &text, int i, int j)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0)
        return false;
    if (j < 0)
    {
        for (int k = 0; k <= i; k++)
        {
            if (pattern[k] != '*')
                return false;
        }
        return true;
    }
    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return solve(pattern, text, i - 1, j - 1);
    }
    if (pattern[i] == '*')
    {
        return solve(pattern, text, i - 1, j) || solve(pattern, text, i, j - 1);
    }
    return false;
}
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.length();
    int m = text.length();
    return solve(pattern, text, n - 1, m - 1);
}

// MEMOIZATION
bool solve(string &pattern, string &text, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0)
        return false;
    if (j < 0)
    {
        for (int k = 0; k <= i; k++)
        {
            if (pattern[k] != '*')
                return false;
        }
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return dp[i][j] = solve(pattern, text, i - 1, j - 1);
    }
    if (pattern[i] == '*')
    {
        return dp[i][j] = (solve(pattern, text, i - 1, j) || solve(pattern, text, i, j - 1));
    }
    return false;
}
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.length();
    int m = text.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(pattern, text, n - 1, m - 1, dp);
}

// TABULATION
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.length();
    int m = text.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int k = 1; k <= i; k++)
        {
            if (pattern[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (pattern[i - 1] == '*')
            {
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{

    return 0;
}