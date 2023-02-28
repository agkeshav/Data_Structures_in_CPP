#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int i = 0, j = 0;
    int ans = 0;
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
        if (mp.size() < (j - i + 1))
        {
            while (mp.size() < (j - i + 1))
            {
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]--;
                }
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
                if (mp.size() == (j - i + 1))
                {
                    ans = max(ans, (j - i + 1));
                }
            }
            j++;
        }
        else if (mp.size() == (j - i + 1))
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
int main()
{

    return 0;
}