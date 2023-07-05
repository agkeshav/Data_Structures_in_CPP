#include <bits/stdc++.h>
using namespace std;
// RECURSION
int solve(string str1, string str2, int i, int j)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (str1[i] == str2[j])
    {
        return solve(str1, str2, i - 1, j - 1);
    }
    else
    {
        int dele = 1 + solve(str1, str2, i - 1, j);
        int insert = 1 + solve(str1, str2, i, j - 1);
        int replace = 1 + solve(str1, str2, i - 1, j - 1);
        return min(dele, min(insert, replace));
    }
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.length();
    int m = str2.length();
    return solve(str1, str2, n - 1, m - 1);
}

// MEMOIZATION
int solve(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (str1[i] == str2[j])
    {
        return dp[i][j] = solve(str1, str2, i - 1, j - 1, dp);
    }
    else
    {
        int dele = 1 + solve(str1, str2, i - 1, j, dp);
        int insert = 1 + solve(str1, str2, i, j - 1, dp);
        int replace = 1 + solve(str1, str2, i - 1, j - 1, dp);
        return dp[i][j] = min(dele, min(insert, replace));
    }
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(str1, str2, n - 1, m - 1, dp);
}

// TABULATION
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int dele = 1 + dp[i - 1][j];
                int insert = 1 + dp[i][j - 1];
                int replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(dele, min(insert, replace));
            }
        }
    }

    return dp[n][m];
}

// SPACE OPTIMISED

int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.length();
    int m = str2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                int dele = 1 + prev[j];
                int insert = 1 + curr[j - 1];
                int replace = 1 + prev[j - 1];
                curr[j] = min(dele, min(insert, replace));
            }
        }
        prev = curr;
    }

    return prev[m];
}
int main()
{

    return 0;
}