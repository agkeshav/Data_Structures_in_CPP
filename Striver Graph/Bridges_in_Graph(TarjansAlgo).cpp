#include <bits/stdc++.h>
using namespace std;
int timer = 0;
void dfs(int node, int parent, vector<int> adj[], vector<int> &visited, vector<int> &time, vector<int> &low, vector<vector<int>> &bridges)
{

    visited[node] = true;
    time[node] = low[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
        {
            continue;
        }
        if (visited[it] == 0)
        {
            dfs(it, node, adj, visited, time, low, bridges);
            low[node] = min(low[node], low[it]);
            if (low[it] > time[node])
            {
                bridges.push_back({it, node});
            }
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> time(n), visited(n, 0), low(n);
    vector<vector<int>> bridges;
    dfs(0, -1, adj, visited, time, low, bridges);
    return bridges;
}
int main()
{

    return 0;
}