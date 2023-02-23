#include <bits/stdc++.h>
using namespace std;
int countOccurences(string pat, string txt)
{
    int k = pat.length();

    int i = 0, j = 0;
    int ans = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < pat.length(); i++)
    {
        mp[pat[i]]++;
    }
    int count = mp.size();
    while (j < txt.length())
    {
        if (mp.find(txt[j]) != mp.end())
        {
            mp[txt[j]]--;
            if (mp[txt[j]] == 0)
            {
                count--;
            }
        }

        if ((j - i + 1) < k)
        {
            j++;
        }
        else if ((j - i + 1) == k)
        {
            if (count == 0)
            {
                ans++;
            }
            if (mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]++;
                if (mp[txt[i]] == 1)
                {
                    count++;
                }
            }

            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    string pat = "for";
    string txt = "forxxorfxdofr";
    cout << countOccurences(pat, txt) << endl;
    return 0;
}