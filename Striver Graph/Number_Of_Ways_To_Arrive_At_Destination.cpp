#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int countPaths(int n, vector<vector<int>> &roads)
{
    // code here
    unordered_map<int, vector<pair<int, long>>> adj;
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<long> ways(n, 0);
    vector<int> dist(n, 1e10);
    ways[0] = 1;
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (pq.size() > 0)
    {
        pair<int, int> front = pq.top();
        int dis = front.first;
        int node = front.second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            long edgeWt = it.second;
            if (dis + edgeWt < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWt;
                ways[adjNode] = ways[node];
                pq.push({dist[adjNode], adjNode});
            }
            else if (dis + edgeWt == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1] % mod;
}
int main()
{

    return 0;
}