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
    bool possible(int newX, int newY, vector<vector<int>> &visited)
    {
        return (newX >= 0 && newX < visited.size() && newY >= 0 && newY < visited[0].size() && visited[newX][newY] == 1);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        vector<vector<int>> visited(n, vector<int>(m, 0));
        DisjointSet ds(n * m);
        vector<int> parent(n * m, 0);
        for (int i = 0; i < n * m; i++)
            parent[i] = i;
        int cnt = 0;
        vector<int> ans;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < operators.size(); i++)
        {
            int x = operators[i][0];
            int y = operators[i][1];
            if (!visited[x][y])
            {
                cnt++;
                visited[x][y] = 1;
                for (int k = 0; k < 4; k++)
                {
                    int newX = x + dx[k];
                    int newY = y + dy[k];
                    if (possible(newX, newY, visited))
                    {
                        if (ds.findUParent(x * m + y) != ds.findUParent(newX * m + newY))
                        {
                            cnt--;
                            ds.UnionByRank(x * m + y, newX * m + newY);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
int main()
{

    return 0;
}