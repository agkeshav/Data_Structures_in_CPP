#include <bits/stdc++.h>
using namespace std;
// works for multiple components as well
bool isCyclic(int V, vector<int> adj[])
{
    // code here

    vector<int> visited(V, 0);
    vector<int> indegree(V, 0);
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        for (auto adjacentNode : adj[i])
        {
            indegree[adjacentNode]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && indegree[i] == 0)
        {
            q.push(i);
            visited[i] = 1;
        }
    }

    while (q.size() > 0)
    {
        int node = q.front();
        q.pop();
        count++;
        for (auto adjacentNode : adj[node])
        {
            indegree[adjacentNode]--;
            if (indegree[adjacentNode] == 0 && visited[adjacentNode] == 0)
            {
                q.push(adjacentNode);
                visited[adjacentNode] = 1;
            }
        }
    }

    return (count != V);
}
int main()
{

    return 0;
}