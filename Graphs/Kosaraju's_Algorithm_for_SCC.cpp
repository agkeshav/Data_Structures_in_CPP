#include <bits/stdc++.h>
using namespace std;
void topoSort(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, stack<int> &st)
{
    vis[node] = true;
    for (auto neigbour : adj[node])
    {
        if (!vis[neigbour])
        {
            topoSort(neigbour, adj, vis, st);
        }
    }
    st.push(node);
}
void dfs(int node, unordered_map<int, list<int>> &transpose, unordered_map<int, bool> &vis)
{
    vis[node] = true;
    for (auto neighbour : transpose[node])
    {
        if (!vis[neighbour])
        {
            dfs(neighbour, transpose, vis);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, st);
        }
    }

    // transpose the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
        for (auto neighbour : adj[i])
        {
            transpose[neighbour].push_back(i);
        }
    }

    // do dfs on based of topo sort ordering
    int count = 0;
    while (st.size() > 0)
    {
        int a = st.top();
        st.pop();
        if (!vis[a])
        {
            count++;
            dfs(a, transpose, vis);
        }
    }
    return count;
}
int main()
{

    return 0;
}