#include<bits/stdc++.h>
using namespace std;
bool compare(string a, string b)
{
    if (b.length() + 1 != a.length())
        return false;
    int i = 0, j = 0;
    while (i < a.size())
    {
        if (j < b.length() && a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return (i == a.length() && j == b.length());
}
static bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(), comp);
    int n = words.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (compare(words[i], words[j]) && dp[i] < 1 + dp[j])
            {
                dp[i] = 1 + dp[j];
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int main(){

return 0;
}