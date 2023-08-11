#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    vector<vector<string>> ans;
    queue<vector<string>> q;
    unordered_map<string, int> mp;
    for (auto it : wordList)
    {
        mp[it]++;
    }
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    while (q.size() > 0)
    {

        vector<string> front = q.front();
        q.pop();
        if (front.size() > level)
        {
            level++;
            for (auto it : usedOnLevel)
            {
                mp.erase(it);
            }
        }

        string word = front.back();
        if (word == endWord)
        {
            if (ans.size() == 0)
            {
                ans.push_back(front);
            }
            else if (ans[0].size() == front.size())
            {
                ans.push_back(front);
            }
        }
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mp.find(word) != mp.end())
                {
                    front.push_back(word);
                    q.push(front);
                    usedOnLevel.push_back(word);
                    front.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}
int main()
{

    return 0;
}