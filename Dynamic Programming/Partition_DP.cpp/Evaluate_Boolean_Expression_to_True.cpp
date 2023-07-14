#include <bits/stdc++.h>
using namespace std;
// RECURSION
int solve(int i, int j, int isTrue, string &exp)
{
    if (i == j)
    {
        if (isTrue == 1)
            return (exp[i] == 'T');
        else
            return (exp[i] == 'F');
    }
    int ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int lt = solve(i, ind - 1, 1, exp);
        int lf = solve(i, ind - 1, 0, exp);
        int rt = solve(ind + 1, j, 1, exp);
        int rf = solve(ind + 1, j, 0, exp);
        if (exp[ind] == '&')
        {
            if (isTrue == 1)
            {
                ways += lt * rt;
            }
            else
            {
                ways += lf * rf + lt * rf + lf * rt;
            }
        }
        else if (exp[ind] == '|')
        {
            if (isTrue == 1)
            {
                ways += lt * rt + lt * rf + lf * rt;
            }
            else
            {
                ways += lf * rf;
            }
        }
        else if (exp[ind] == '^')
        {
            if (isTrue == 1)
            {
                ways += lf * rt + lt * rf;
            }
            else
            {
                ways += lt * rt + lf * rf;
            }
        }
    }
    return ways;
}
int evaluateExp(string &exp)
{
    // Write your code here.
    int n = exp.size();
    return solve(0, n - 1, 1, exp);
}
// MEMOIZATION
const int mod = 1e9 + 7;
long long solve(int i, int j, int isTrue, string &exp, vector<vector<vector<int>>> &dp)
{
    if (i == j)
    {
        if (isTrue == 1)
            return (exp[i] == 'T');
        else
            return (exp[i] == 'F');
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int lt = solve(i, ind - 1, 1, exp, dp);
        int lf = solve(i, ind - 1, 0, exp, dp);
        int rt = solve(ind + 1, j, 1, exp, dp);
        int rf = solve(ind + 1, j, 0, exp, dp);
        if (exp[ind] == '&')
        {
            if (isTrue == 1)
            {
                ways = (ways % mod + (lt * rt) % mod) % mod;
            }
            else
            {
                ways = (ways % mod + ((lf * rf) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod) % mod;
            }
        }
        else if (exp[ind] == '|')
        {
            if (isTrue == 1)
            {
                ways = (ways % mod + ((lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod) % mod;
            }
            else
            {
                ways = (ways % mod + (lf * rf) % mod) % mod;
            }
        }
        else if (exp[ind] == '^')
        {
            if (isTrue == 1)
            {
                ways = (ways % mod + ((lf * rt) % mod + (lt * rf) % mod) % mod) % mod;
            }
            else
            {
                ways = (ways % mod + ((lt * rt) % mod + (lf * rf) % mod) % mod) % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways % mod;
}
int evaluateExp(string &exp)
{
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return solve(0, n - 1, 1, exp, dp);
}

int main()
{

    return 0;
}