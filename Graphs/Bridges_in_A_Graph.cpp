#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<vector<int>> &bridges, int &timer)
{
    visited[node] = true;
    disc[node] = low[node] = timer;
    timer++;
    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;
        if (!visited[neighbour])
        {
            dfs(neighbour, node, adj, visited, disc, low, bridges, timer);
            low[node] = min(low[node], low[neighbour]);
            if (low[neighbour] > disc[node])
            {
                bridges.push_back({node, neighbour});
            }
        }
        else
        {
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> bridges;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    vector<bool> visited(v, false);
    int timer = 0;
    int parent = -1;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfs(i, parent, adj, visited, disc, low, bridges, timer);
        }
    }

    return bridges;
}
int main()
{

    return 0;
}