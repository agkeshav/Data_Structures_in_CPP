#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (u == v)
            return;
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (u == v)
            return;
        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
class Solution
{
public:
    bool isPossible(int x, int y, vector<vector<int>> &grid)
    {
        return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size());
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        DisjointSet ds(grid.size() * grid[0].size() - 1);
        int columns = grid[0].size();
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (isPossible(i + dx[k], j + dy[k], grid))
                        {
                            if (grid[i + dx[k]][j + dy[k]] == 1)
                            {
                                int c = i * columns + j;
                                int d = (i + dx[k]) * columns + (j + dy[k]);
                                ds.unionBySize(c, d);
                            }
                        }
                    }
                }
            }
        }
        // row * columns + cols
        int maxi = *max_element(ds.size.begin(), ds.size.end());
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    set<int> st;
                    for (int k = 0; k < 4; k++)
                    {
                        if (isPossible(i + dx[k], j + dy[k], grid))
                        {
                            if (grid[i + dx[k]][j + dy[k]] == 1)
                                st.insert(ds.findParent((i + dx[k]) * columns + (j + dy[k])));
                        }
                    }
                    int sum = 0;
                    for (auto it : st)
                    {
                        sum += ds.size[it];
                    }
                    maxi = max(maxi, sum + 1);
                }
            }
        }
        return maxi;
    }
};
int main()
{

    return 0;
}