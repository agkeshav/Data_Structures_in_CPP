#include <bits/stdc++.h>
using namespace std;
bool check(int src, int parent, int V, vector<int> adj[], vector<int> &visited)
{
    visited[src] = true;
    for (auto it : adj[src])
    {
        if (visited[it] == 0)
        {
            if (check(it, src, V, adj, visited))
                return true;
        }
        else if (parent != it)
        {
            return true;
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
            if (check(i, -1, V, adj, visited))
                return true;
        }
    }
    return false;
}
int main()
{

    return 0;
}