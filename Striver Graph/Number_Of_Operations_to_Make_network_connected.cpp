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
void dfs(int node, vector<int> &visited, unordered_map<int, vector<int>> &mp)
{
    visited[node] = true;
    for (auto it : mp[node])
    {
        if (visited[it] == 0)
            dfs(it, visited, mp);
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    // wo cables jo cycle form kr rhi hain wo nikal lete
    // aur number of components nikal lete hai
    unordered_map<int, vector<int>> mp;
    for (auto it : connections)
    {
        mp[it[0]].push_back(it[1]);
        mp[it[1]].push_back(it[0]);
    }
    vector<int> visited(n, 0);
    int compo = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            compo++;
            dfs(i, visited, mp);
        }
    }

    // now find how many edges are forming cycle;
    vector<int> parent(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int edges = 0;
    for (auto it : connections)
    {
        if (findParent(it[0], parent) != findParent(it[1], parent))
        {
            unionByRank(it[0], it[1], parent);
        }
        else
        {
            edges++;
        }
    }
    cout << edges << " " << compo << endl;
    if (edges >= compo - 1)
        return compo - 1;
    else
        return -1;
}
int main()
{

    return 0;
}