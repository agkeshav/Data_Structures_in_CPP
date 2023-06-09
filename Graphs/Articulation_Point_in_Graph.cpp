#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, unordered_map<int, list<int>> &adj, vector<int> &ap, vector<int> &disc, vector<int> &low, vector<bool> &visited, int &timer)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;
        if (!visited[neighbour])
        {
            dfs(neighbour, node, adj, ap, disc, low, visited, timer);
            low[node] = min(low[node], low[neighbour]);
            if (low[neighbour] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], disc[neighbour]);
        }
    }
    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}
int main()
{
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back({0, 1});
    edges.push_back({0, 3});
    edges.push_back({0, 4});
    edges.push_back({3, 4});
    edges.push_back({1, 2});
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    int n = 5; // no of vertices
    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> visited(n, false);
    int parent = -1;
    vector<int> articulationPoints(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, adj, articulationPoints, disc, low, visited, timer);
        }
    }

    cout << "Articulation Points are:-" << endl;

    for (int i = 0; i < n; i++)
    {
        if (articulationPoints[i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}