#include <bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    vector<int> visited(V, 0);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (q.size() > 0)
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto it : adj[u])
        {
            if (visited[it] == 0)
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}