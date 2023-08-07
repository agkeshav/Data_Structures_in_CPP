#include <bits/stdc++.h>
using namespace std;
bool possible(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited)
{
    return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && visited[i][j] == 0 && grid[i][j] == '1');
}
void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited)
{
    visited[i][j] = 1;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, +1, -1};
    for (int k = 0; k < 4; k++)
    {
        int newX = i + dx[k];
        int newY = j + dy[k];
        if (possible(newX, newY, grid, visited))
        {
            dfs(newX, newY, grid, visited);
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1' && visited[i][j] == 0)
            {
                ans++;
                dfs(i, j, grid, visited);
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}