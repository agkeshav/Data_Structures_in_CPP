#include <bits/stdc++.h>
using namespace std;
bool dfsCheck(int node, vector<vector<int>> &graph, vector<int> &visited, vector<int> &pathVisited,
              vector<int> &check)
{
    visited[node] = 1;
    pathVisited[node] = 1;
    for (auto it : graph[node])
    {
        if (!visited[it])
        {
            if (dfsCheck(it, graph, visited, pathVisited, check))
            {
                check[node] = 0;
                return true;
            }
        }
        else if (pathVisited[it])
        {
            check[node] = 0;
            return true;
        }
    }
    check[node] = 1;
    pathVisited[node] = 0;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    vector<int> ans;
    int v = graph.size();
    vector<int> check(v, 0);
    vector<int> visited(v, 0);
    vector<int> pathVisited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfsCheck(i, graph, visited, pathVisited, check);
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (check[i] == 1)
            ans.push_back(i);
    }
    return ans;
}

// USING BFS
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    vector<int> ans;
    int v = graph.size();
    vector<int> visited(v, 0);
    vector<int> indegree(v, 0);
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < graph.size(); i++)
    {
        for (auto it : graph[i])
        {
            adj[it].push_back(i);
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            visited[i] = 1;
        }
    }
    while (q.size() > 0)
    {
        int u = q.front();
        ans.push_back(u);
        q.pop();
        for (auto it : adj[u])
        {
            indegree[it]--;
            if (!visited[it] && indegree[it] == 0)
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}