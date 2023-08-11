#include <bits/stdc++.h>
using namespace std;
void dfs(int node, unordered_map<int, vector<pair<int, int>>> &adj, stack<int> &st, unordered_map<int, int> &visited)
{
    visited[node] = 1;
    for (auto adjacent : adj[node])
    {
        if (visited.find(adjacent.first) == visited.end())
            dfs(adjacent.first, adj, st, visited);
    }
    st.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // code here
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    stack<int> st;
    unordered_map<int, int> visited;
    for (int i = 0; i < N; i++)
    {
        if (visited.find(i) == visited.end())
        {
            dfs(i, adj, st, visited);
        }
    }

    vector<int> dist(N, 1e9);
    dist[0] = 0;
    while (st.size() > 0)
    {
        int node = st.top();
        st.pop();
        for (auto adjacent : adj[node])
        {
            int u = adjacent.first;
            int wt = adjacent.second;
            if (dist[node] + wt < dist[u])
            {
                dist[u] = dist[node] + wt;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}
int main()
{

    return 0;
}