#include <bits/stdc++.h>
using namespace std;
bool isCycleBFS(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    parent[node] = -1;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto neighbours : adj[temp])
        {
            if (visited[neighbours] == 1 && neighbours != parent[temp])
            {
                return true;
            }
            else if (visited[neighbours] == false)
            {
                q.push(neighbours);
                visited[neighbours] = true;
                parent[neighbours] = temp;
            }
        }
    }
    return false;
}
bool isCycleDFS(int node, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (visited[neighbour] == false)
        {
            bool cycleDetect = isCycleDFS(neighbour, node, adj, visited);
            if (cycleDetect)
            {
                return true;
            }
        }
        else if (neighbour != parent){
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    // create adjacency list first
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // make visited and parent data structures
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCycleBFS(i, adj, visited);
            if (ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
string cycleDetectionDFS(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    // create adjacency list first
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // make visited and parent data structures
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCycleDFS(i, -1, adj, visited);
            if (ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
int main()
{

    return 0;
}