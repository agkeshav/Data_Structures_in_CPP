#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<vector<int>> &graph, vector<int> &color, int col)
{
    color[node] = col;
    for (auto it : graph[node])
    {
        if (color[it] == -1)
        {
            if (dfs(it, graph, color, !col) == false)
                return false;
        }
        else if (color[it] != -1 && color[it] == color[node])
        {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(i, graph, color, 0) == false)
                return false;
        }
    }
    return true;
}
int main()
{

    return 0;
}