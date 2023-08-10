#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;

    vector<int> visited(V, 0);
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            queue<int> q;
            for (int i = 0; i < V; i++)
            {
                if (indegree[i] == 0)
                {
                    visited[i] = 1;
                    q.push(i);
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
        }
    }

    return ans;
}
int main()
{

    return 0;
}