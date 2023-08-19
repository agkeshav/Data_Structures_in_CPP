#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

public:
    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]); // Path compression
    }

    void UnionByRank(int u, int v)
    {
        int ulPU = findUParent(u);
        int ulPV = findUParent(v);
        if (ulPU == ulPV)
            return;

        if (rank[ulPU] < rank[ulPV])
        {
            parent[ulPU] = ulPV;
        }
        else if (rank[ulPU] > rank[ulPV])
        {
            parent[ulPV] = ulPU;
        }
        else
        {
            parent[ulPV] = ulPU;
            rank[ulPU]++;
        }
    }
    void UnionBySize(int u, int v)
    {
        int ulPU = findUParent(u);
        int ulPV = findUParent(v);
        if (ulPU == ulPU)
            return;

        if (size[ulPU] < size[ulPV])
        {
            parent[ulPU] = ulPV;
            size[ulPV] += size[ulPU];
        }
        else
        {
            parent[ulPV] = ulPU;
            size[ulPU] += size[ulPV];
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here

        int sum = 0;
        vector<pair<int, int>> mst;
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }

        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        for (int i = 0; i < edges.size(); i++)
        {
            int wt = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if (ds.findUParent(u) != ds.findUParent(v))
            {
                sum += wt;
                // cout<<sum<<endl;
                ds.UnionByRank(u, v);
                mst.push_back({u, v});
            }
        }
        // for(auto it:mst) cout<<it.first<<" "<<it.second<<endl;
        return sum;
    }
};
int main()
{

    return 0;
}