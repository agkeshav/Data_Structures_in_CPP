#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findParent(vector<int> &parent, int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent, parent[node]);
    }
    void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (u == v)
            return;
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> rank(n + 1, 0);
        vector<int> parent;
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                    unionByRank(i + 1, j + 1, parent, rank);
                ;
            }
        }
        int cnt = 0;
        for (int i = 1; i < parent.size(); i++)
        {

            if (parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};
int main()
{

    return 0;
}