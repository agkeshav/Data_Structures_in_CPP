#include <bits/stdc++.h>
using namespace std;
bool possible(int i, int j, vector<vector<int>> &visited)
{
    int n = visited.size();
    int m = visited[0].size();
    return (i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == 0);
}
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j])
            {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
                
            }
        }
    }

    while (q.size() > 0)
    {
        pair<pair<int, int>, int> front = q.front();
        int i = front.first.first;
        int j = front.first.second;
        int dist = front.second;
        ans[i][j] = dist;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int newX = i + dx[k];
            int newY = j + dy[k];
            if (possible(newX, newY, visited))
            {
                q.push({{newX, newY}, dist + 1});
                visited[newX][newY] = 1;
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}