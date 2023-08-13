#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Code here
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<int> path;
    vector<int> parent(n + 1, -1);
    vector<int> dist(n + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist , node
    pq.push({0, 1});
    dist[1] = 0;
    while (pq.size() > 0)
    {
        pair<int, int> top = pq.top();
        int dis = top.first;
        int node = top.second;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWt = it.second;
            if (dis + edgeWt < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWt;
                parent[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    if (dist[n] == 1e9)
        return {-1};
    int node = n;
    while (parent[node] != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}
int main()
{

    return 0;
}