#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve(int index, string s, vector<string> &output, vector<vector<string>> &ans)
{
    if (index == s.length())
    {
        ans.push_back(output);
        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            output.push_back(s.substr(index, i - index + 1));
            solve(i + 1, s, output, ans);
            output.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> output;
    solve(0, s, output, ans);
    return ans;
}
int main()
{

    return 0;
}