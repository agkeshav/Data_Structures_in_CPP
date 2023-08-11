#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // code here
    unordered_map<int, vector<int>> adj;
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> dist(N, 1e9);
    dist[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    while (q.size() > 0)
    {
        pair<int,int> p = q.front();
        int node = p.first;
        int distance = p.second;
        q.pop();
        for (auto adjacentNode : adj[node])
        {
            if (distance + 1 < dist[adjacentNode])
            {
                dist[adjacentNode] = 1 + distance;
                q.push({adjacentNode, dist[adjacentNode]});
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
int main(){

return 0;
}