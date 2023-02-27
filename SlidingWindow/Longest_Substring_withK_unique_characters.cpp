#include <bits/stdc++.h>
using namespace std;
int longestKSubstr(string s, int k)
{
    // your code here
    int i = 0, j = 0;
    int ans = -1;
    unordered_map<char, int> mp;
    while (j < s.length())
    {
        if (mp.find(s[j]) == mp.end())
        {
            mp.insert({s[j], 1});
        }
        else
        {
            mp[s[j]]++;
        }
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            ans = max(ans, (j - i + 1));
            j++;
        }
        else
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
                if (mp.size() == k)
                {
                    ans = max(ans, (j - i + 1));
                }
            }
            j++;
        }
    }
    return ans;
}
int main()
{

    return 0;
}