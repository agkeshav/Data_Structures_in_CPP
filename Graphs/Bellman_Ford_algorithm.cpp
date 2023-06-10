#include <bits/stdc++.h>
using namespace std;
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;
    // Running the loop n-1 times
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (dist[u] != 1e9 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    // To check negative cycle
    bool flag = false;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (dist[u] != 1e9 && dist[u] + w < dist[v])
        {
            flag = true;
            break;
        }
    }
    if (!flag)
        return dist[dest];
}
int main()
{

    return 0;
}