#include <bits/stdc++.h>
using namespace std;
void solve(unordered_map<string, int> &store, int level, vector<string> &output, vector<vector<string>> &ans, string &endWord, string end)
{
    if (output.size() == store[end])
    {
        for (auto it : output)
            cout << it << endl;
        reverse(output.begin(), output.end());
        output.push_back(end);
        ans.push_back(output);
        output.pop_back();
        reverse(output.begin(), output.end());
        return;
    }
    string s = endWord;
    for (int i = 0; i < s.length(); i++)
    {

        for (char c = 'a'; c <= 'z'; c++)
        {
            endWord[i] = c;
            if (store.find(endWord) != store.end() && store[endWord] == level - 1)
            {
                output.push_back(endWord);
                solve(store, level - 1, output, ans, endWord, end);
                output.pop_back();
            }
        }
        endWord = s;
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    unordered_map<string, int> store;
    for (auto it : wordList)
    {
        mp[it]++;
    }
    if (mp.find(endWord) == mp.end())
        return ans;

    queue<pair<string, int>> q;
    q.push({beginWord, 0});
    mp.erase(beginWord);
    while (q.size() > 0)
    {
        pair<string, int> front = q.front();
        string str = front.first;
        int level = front.second;
        store[str] = level;
        if (str == endWord)
        {
            break;
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
    vector<string> output;
    int lvl = store[endWord];
    if (lvl == 0)
        return ans;
    solve(store, lvl, output, ans, endWord, endWord);
    return ans;
}
int main()
{

    return 0;
}