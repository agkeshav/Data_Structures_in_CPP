#include <bits/stdc++.h>
using namespace std;
void topologicalSortDFS(int node, unordered_map<int, bool> &visited, vector<int> adj[], stack<int> &st)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topologicalSortDFS(neighbour, visited, adj, st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSortDFS(i, visited, adj, st);
        }
    }
    while (!st.empty())
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