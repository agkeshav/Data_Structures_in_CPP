#include <bits/stdc++.h>
using namespace std;
bool possible(int newRow, int newCol, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    return (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] && !visited[newRow][newCol]);
}
void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &vec,
         int row0, int col0)
{
    visited[row][col] = true;
    vec.push_back({row - row0, col - col0});
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int k = 0; k < 4; k++)
    {
        int newRow = row + dx[k];
        int newCol = col + dy[k];
        if (possible(newRow, newCol, grid, visited))
        {
            dfs(newRow, newCol, visited, grid, vec, row0, col0);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j])
            {
                vector<pair<int, int>> vec;
                dfs(i, j, visited, grid, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}
int main()
{

    return 0;
}