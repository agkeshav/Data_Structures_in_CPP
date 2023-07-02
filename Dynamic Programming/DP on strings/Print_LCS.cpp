#include <bits/stdc++.h>
using namespace std;
string lcs(string s, string t)
{
    // Write your code here
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
    int n = s.length();
    int m = t.length();
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= t.length(); j++)
        {
            if (s[i - 1] == t[j - 1])
            {

                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int left = dp[i - 1][j];
                int right = dp[i][j - 1];
                dp[i][j] = 0 + max(left, right);
            }
        }
    }
    string answer = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            answer.push_back(s[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
int main()
{
    cout << lcs("abcde", "bdgek") << endl;
    return 0;
}