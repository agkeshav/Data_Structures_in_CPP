#include <bits/stdc++.h>
using namespace std;
vector<string> AllPossibleStrings(string s)
{
    // Code here
    int n = s.length();
    vector<string> ans;
    for (int num = 0; num <= pow(2, n) - 1; num++)
    {
        string str;
        for (int i = 0; i < n; i++)
        {
            if ((num & (1 << i)) != 0)
            {
                str.push_back(s[i]);
            }
        }
        if (str.length() != 0)
        {
            ans.push_back(str);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}