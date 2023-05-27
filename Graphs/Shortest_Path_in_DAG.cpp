#include <bits/stdc++.h>
using namespace std;
void topoSort(int node, unordered_map<int, list<pair<int, int>>> &adj, stack<int> &st, int N, int M, unordered_map<int, int> &visited)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour.first])
        {
            topoSort(neighbour.first, adj, st, N, M, visited);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // code here
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v, w));
    }
    stack<int> st;
    unordered_map<int, int> visited;

    // Topological Sort
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            topoSort(i, adj, st, N, M, visited);
        }
    }
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        if (dist[node] != INT_MAX)
        {
            for (auto neighbour : adj[node])
            {
                if (dist[node] + neighbour.second < dist[neighbour.first])
                {
                    dist[neighbour.first] = dist[node] + neighbour.second;
                }
            }
        }
    }
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INT_MAX)
        {
            dist[i] = -1;
        }
    }
    return dist;
}
int main()
{

    return 0;
}