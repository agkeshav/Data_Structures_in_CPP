#include <bits/stdc++.h>
using namespace std;
bool possible(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && visited[i][j] == 0 && grid[i][j] == 1);
}
int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
            }
        }
    }
    int maxi = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, +1, -1};
    while (q.size() > 0)
    {
        pair<pair<int, int>, int> front = q.front();
        int t = front.second;
        maxi = max(maxi, t);
        int i = front.first.first;
        int j = front.first.second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int newX = i + dx[k];
            int newY = j + dy[k];
            if (possible(newX, newY, grid, visited))
            {
                q.push({{newX, newY}, t + 1});
                visited[newX][newY] = 1;
                grid[newX][newY] = 2;
            }
        }
    }
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return maxi;
}
int main()
{

    return 0;
}