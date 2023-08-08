#include <bits/stdc++.h>
using namespace std;
int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dx = {-1, +1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        if (visited[i][0] == 0 && grid[i][0] == 1)
        {
            q.push({i, 0});
            visited[i][0] = 1;
        }
        if (visited[i][n - 1] == 0 && grid[i][n - 1] == 1)
        {
            q.push({i, n - 1});
            visited[i][n - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[0][i] == 0 && grid[0][i] == 1)
        {
            q.push({0, i});
            visited[0][i] = 1;
        }
        if (visited[m - 1][i] == 0 && grid[m - 1][i] == 1)
        {
            q.push({m - 1, i});
            visited[m - 1][i] = 1;
        }
    }
    while (q.size() > 0)
    {
        pair<int, int> front = q.front();
        int i = front.first;
        int j = front.second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int newX = i + dx[k];
            int newY = j + dy[k];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1 && visited[newX][newY] == 0)
            {
                q.push({newX, newY});
                visited[newX][newY] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0 && grid[i][j] == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}