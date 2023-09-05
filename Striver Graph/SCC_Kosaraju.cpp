#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &visited, unordered_map<int, vector<int>> &mp)
{
    visited[node] = true;
    for (auto it : mp[node])
    {
        if (visited[it] == 0)
        {
            dfs(it, visited, mp);
        }
    }
}
void dfsMark(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
            dfsMark(it, vis, adj, st);
    }
    st.push(node);
}
int kosaraju(int V, vector<vector<int>> &adj)
{
    // code here
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            dfsMark(i, vis, adj, st);
        }
    }
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < V; i++)
    {
        vector<int> v = adj[i];
        for (auto it : v)
        {
            mp[it].push_back(i);
        }
    }
    int scc = 0;
    vector<int> visited(V, 0);
    while (st.size() > 0)
    {
        int i = st.top();
        if (visited[i] == 0)
        {
            scc++;
            dfs(i, visited, mp);
        }
        else
        {
            st.pop();
        }
    }
    return scc;
}
int main()
{

    return 0;
}