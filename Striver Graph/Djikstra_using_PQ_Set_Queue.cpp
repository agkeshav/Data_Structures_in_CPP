#include <bits/stdc++.h>
using namespace std;
// USING PQ
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    dist[S] = 0;
    while (pq.size() > 0)
    {
        pair<int, int> front = pq.top();
        pq.pop();
        int dis = front.first;
        int node = front.second;
        for (auto it : adj[node])
        {
            int edgeWt = it[1];
            int adjNode = it[0];
            if (dis + edgeWt < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

// USING SET

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V, 1e9);
    set<pair<int, int>> st; // dist , node
    st.insert({0, S});
    dist[S] = 0;
    while (st.size() > 0)
    {
        auto it = st.begin();
        pair<int, int> front = *it;
        if (st.find(front) != st.end())
        {
            st.erase(front);
        }
        int dis = front.first;
        int node = front.second;
        for (auto it : adj[node])
        {
            int edgeWt = it[1];
            int adjNode = it[0];
            if (dis + edgeWt < dist[adjNode])
            {
                if (st.find({dist[adjNode], adjNode}) != st.end())
                {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

// USING QUEUE

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V, 1e9);
    queue<pair<int, int>> q; // dist , node
    q.push({0, S});
    dist[S] = 0;
    while (q.size() > 0)
    {
        pair<int, int> front = q.front();
        q.pop();
        int dis = front.first;
        int node = front.second;
        for (auto it : adj[node])
        {
            int edgeWt = it[1];
            int adjNode = it[0];
            if (dis + edgeWt < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWt;
                q.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{

    return 0;
}