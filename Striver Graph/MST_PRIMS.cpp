#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    int sum = 0;
    vector<pair<int, int>> mst;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    vector<int> visited(V, 0);
    // weight , node, parent
    pq.push({0, {0, -1}});
    while (pq.size() > 0)
    {
        pair<int, pair<int, int>> top = pq.top();
        int wt = top.first;
        int node = top.second.first;
        int parent = top.second.second;
        pq.pop();

        if (visited[node] == 1)
            continue;

        visited[node] = 1;
        sum += wt;
        if (parent != -1)
        {
            mst.push_back({node, parent});
        }
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWt = it[1];
            if (visited[adjNode] == 0)
            {
                pq.push({edgeWt, {adjNode, node}});
            }
        }
    }

    // EDGES OF MST ARE:-
    for (auto it : mst)
    {
        cout << it.first << " " << it.second << endl;
    }
    return sum;
}
int main()
{

    return 0;
}