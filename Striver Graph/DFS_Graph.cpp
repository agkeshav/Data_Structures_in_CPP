#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], vector<int> &ans, vector<int> &visited, int node)
{
    visited[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(adj, ans, visited, it);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    vector<int> visited(V, 0);
    dfs(adj, ans, visited, 0);
    return ans;
}
int main()
{

    return 0;
}