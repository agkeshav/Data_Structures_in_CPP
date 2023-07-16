#include <bits/stdc++.h>
using namespace std;
// RECURSION
bool isPalindrome(string str)
{
    int s = 0;
    int e = str.length() - 1;
    while (s <= e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}
int solve(int index, string &str)
{
    if (index == str.length())
        return 0;
    int cost = 1e9;
    string temp = "";
    for (int i = index; i < str.length(); i++)
    {
        temp.push_back(str[i]);
        if (isPalindrome(temp))
        {
            cost = min(cost, 1 + solve(i + 1, str));
        }
    }
    return cost;
}
int palindromePartitioning(string str)
{
    // Write your code here
    return solve(0, str) - 1;
}
// MEMOIZATION
bool isPalindrome(string str)
{
    int s = 0;
    int e = str.length() - 1;
    while (s <= e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}
int solve(int index, string &str, vector<int> &dp)
{
    if (index == str.length())
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int cost = 1e9;
    string temp = "";
    for (int i = index; i < str.length(); i++)
    {
        temp.push_back(str[i]);
        if (isPalindrome(temp))
        {
            cost = min(cost, 1 + solve(i + 1, str, dp));
        }
    }
    return dp[index] = cost;
}
int palindromePartitioning(string str)
{
    // Write your code here
    vector<int> dp(str.length(), -1);
    return solve(0, str, dp) - 1;
}

// TABULATION
bool isPalindrome(string str)
{
    int s = 0;
    int e = str.length() - 1;
    while (s <= e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}
int palindromePartitioning(string str)
{
    // Write your code here
    vector<int> dp(str.length() + 1, 0);
    for (int index = str.length() - 1; index >= 0; index--)
    {
        int cost = 1e9;
        string temp = "";
        for (int i = index; i < str.length(); i++)
        {
            temp.push_back(str[i]);
            if (isPalindrome(temp))
            {
                cost = min(cost, 1 + dp[i + 1]);
            }
        }
        dp[index] = cost;
    }
    return dp[0] - 1;
}
int main()
{

    return 0;
}