#include <bits/stdc++.h>
using namespace std;
bool cycleDFS(int node, vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
{
    visited[node] = true;
    dfsVisited[node] = true;
    for (auto neighbours : adj[node])
    {
        if (visited[neighbours] == false)
        {
            visited[neighbours] = true;
            dfsVisited[neighbours] = true;
            bool cycleDetected = cycleDFS(neighbours, adj, visited, dfsVisited);
            if (cycleDetected)
            {
                return true;
            }
        }
        else if (dfsVisited[neighbours] == true)
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = cycleDFS(i, adj, visited, dfsVisited);
            if (cycleFound == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{

    return 0;
}