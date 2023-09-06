#include<bits/stdc++.h>
using namespace std;
class Solution
{
    int timer = 0;

public:
    void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<int> &ap, vector<int> adj[], vector<int> &vis)
    {

        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (vis[it] == 0)
            {
                dfs(it, node, tin, low, ap, adj, vis);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                {
                    ap[node]++;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            ap[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        vector<int> tin(V, 0);
        vector<int> low(V, 0);
        vector<int> ap(V, 0); // to store articulation points
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, -1, tin, low, ap, adj, vis);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (ap[i] != 0)
                ans.push_back(i);
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};
int main(){

return 0;
}