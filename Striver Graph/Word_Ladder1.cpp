#include <bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_map<string, int> mp;
    for (auto it : wordList)
    {
        mp[it]++;
    }
    if (mp.find(endWord) == mp.end())
        return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    mp.erase(beginWord);
    while (q.size() > 0)
    {
        pair<string, int> front = q.front();
        string str = front.first;
        int level = front.second;
        if (str == endWord)
        {
            return level;
        }
        q.pop();
        string s = str;
        for (int i = 0; i < str.length(); i++)
        {

            for (char c = 'a'; c <= 'z'; c++)
            {
                str[i] = c;
                if (mp.find(str) != mp.end())
                {
                    q.push({str, level + 1});
                    mp.erase(str);
                }
            }
            str = s;
        }
    }
    return 0;
}
int main()
{

    return 0;
}