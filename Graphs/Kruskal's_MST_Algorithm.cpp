#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}
void unionSet(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    sort(edges.begin(), edges.end(), cmp);
    int ans = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        if (findParent(parent, u) != findParent(parent, v))
        {
            ans += edges[i][2];
            unionSet(parent, rank, u, v);
        }
    }
    return ans;
}
int main()
{

    return 0;
}