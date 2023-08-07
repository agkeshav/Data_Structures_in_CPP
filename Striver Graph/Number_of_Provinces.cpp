#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &visited, vector<vector<int>> &isConnected)
{
    visited[node] = true;
    for (int i = 1; i <= isConnected.size(); i++)
    {
        if (i != node && isConnected[node - 1][i - 1] == 1 && visited[i] == false)
        {
            dfs(i, visited, isConnected);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> visited(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            ans++;
            dfs(i, visited, isConnected);
        }
    }
    return ans;
}
int main()
{

    return 0;
}