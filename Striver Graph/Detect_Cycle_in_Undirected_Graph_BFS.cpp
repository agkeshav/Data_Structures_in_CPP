#include <bits/stdc++.h>
using namespace std;
bool check(int src, int V, vector<int> adj[], vector<int> &visited)
{
    queue<pair<int, int>> q;
    q.push({src, -1});
    visited[src] = 1;
    while (q.size() > 0)
    {
        pair<int, int> front = q.front();
        int node = front.first;
        int parent = front.second;
        q.pop();
        for (auto adjacentNode : adj[node])
        {
            if (visited[adjacentNode] == false)
            {
                q.push({adjacentNode, node});
                visited[adjacentNode] = 1;
            }
            else if (visited[adjacentNode] && parent != adjacentNode)
            {
                return true;
            }
        }
    }

    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            if (check(i, V, adj, visited))
                return true;
        }
    }
    return false;
}
int main()
{

    return 0;
}