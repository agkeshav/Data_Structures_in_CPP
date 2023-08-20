#include <bits/stdc++.h>
using namespace std;
int findParent(int node, vector<int> &parent)
{
    if (node == parent[node])
        return node;
    return parent[node] = findParent(parent[node], parent);
}
void unionByRank(int u, int v, vector<int> &parent)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u == v)
        return;
    parent[v] = u;
}
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    vector<int> parent(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    vector<vector<string>> ans(n, {""});
    unordered_map<string, int> mapMails;
    for (int i = 0; i < accounts.size(); i++)
    {
        vector<string> mails = accounts[i];
        for (int j = 1; j < mails.size(); j++)
        {
            if (mapMails.find(mails[j]) == mapMails.end())
            {
                mapMails[mails[j]] = i;
            }
            else
            {
                int u = i;
                int v = mapMails[mails[j]];
                unionByRank(u, v, parent);
            }
        }
    }

    unordered_map<int, vector<string>> store;
    for (auto it : mapMails)
    {
        store[it.second].push_back(it.first);
    }

    for (auto x : store)
    {
        int node = x.first;
        int p = findParent(node, parent);

        if (node == p)
        {
            vector<string> temp;

            for (int j = 0; j < x.second.size(); j++)
            {
                ans[node].push_back(x.second[j]);
            }
        }
        else
        {

            for (int j = 0; j < x.second.size(); j++)
            {
                ans[p].push_back(x.second[j]);
            }
        }
    }
    vector<vector<string>> finalAnswer;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].size() == 1)
            continue;
        vector<string> temp;
        vector<string> a = ans[i];
        int x = mapMails[ans[i][1]];
        temp.push_back(accounts[x].front());
        for (int i = 1; i < a.size(); i++)
        {
            temp.push_back(a[i]);
        }
        finalAnswer.push_back(temp);
    }

    for (int i = 0; i < finalAnswer.size(); i++)
    {
        sort(finalAnswer[i].begin() + 1, finalAnswer[i].end());
    }
    return finalAnswer;
}
int main()
{

    return 0;
}