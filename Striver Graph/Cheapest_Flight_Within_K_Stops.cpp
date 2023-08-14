
#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {src, 0}});
    while (pq.size() > 0)
    {
        pair<int, pair<int, int>> front = pq.front();
        int dis = front.first;
        int node = front.second.first;
        int stops = front.second.second;
        pq.pop();
        if (stops > k)
            continue;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgWt = it.second;
            if (dis + edgWt < dist[adjNode] && stops <= k)
            {
                dist[adjNode] = dis + edgWt;
                pq.push({dist[adjNode], {adjNode, stops + 1}});
            }
        }
    }
    if (dist[dst] == 1e9)
    {
        return -1;
    }
    else
    {
        return dist[dst];
    }
}
int main()
{

    return 0;
}