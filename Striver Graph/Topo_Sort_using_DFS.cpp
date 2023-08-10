#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st)
{
    visited[node] = 1;
    for (auto adjacentNodes : adj[node])
    {
        if (!visited[adjacentNodes])
        {
            dfs(adjacentNodes, adj, visited, st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;
    stack<int> st;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }
    while (st.size() > 0)
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main()
{

    return 0;
}