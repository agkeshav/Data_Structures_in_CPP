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
int main()
{

    return 0;
}