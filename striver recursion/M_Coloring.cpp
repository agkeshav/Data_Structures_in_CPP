#include <bits/stdc++.h>
using namespace std;
bool possible(int node, int m, int n, bool graph[101][101], int col, vector<int> &nodeColor)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && nodeColor[k] == col)
        {
            return false;
        }
    }
    return true;
}
bool solve(int startingNode, vector<int> &nodeColor, bool graph[101][101], int m, int n)
{
    if (startingNode == n)
    {
        return true;
    }

    for (int col = 1; col <= m; col++)
    {
        if (possible(startingNode, m, n, graph, col, nodeColor))
        {
            nodeColor[startingNode] = col;
            if (solve(startingNode + 1, nodeColor, graph, m, n) == true)
                return true;
            nodeColor[startingNode] = 0;
        }
    }
    return false;
}
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int> nodeColor(n, -1);
    int startingNode = 0;
    bool ans = solve(startingNode, nodeColor, graph, m, n);
    return ans;
}
int main()
{

    return 0;
}