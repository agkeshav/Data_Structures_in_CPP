#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<int> indegree(v);
    vector<int> visited(v);

    queue<int> q;
    for (auto nodes : adj)
    {
        for (auto j : nodes.second)
        {
            indegree[j]++;
        }
    }
    vector<int> ans;

    // 0 indegree walo ko push krdo
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        visited[front] = 1;
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}