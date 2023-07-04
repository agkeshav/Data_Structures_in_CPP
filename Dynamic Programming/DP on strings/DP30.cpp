#include <bits/stdc++.h>
using namespace std;
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.length();
    int m = ptr.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == ptr[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int deletions = str.length() - dp[n][m];
    int insertions = ptr.length() - dp[n][m];
    return deletions + insertions;
}
int main()
{

    return 0;
}