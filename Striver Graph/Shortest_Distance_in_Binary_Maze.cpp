#include <bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination)
{
    // code here
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source.first, source.second}});
    vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), 1e9));
    dist[source.first][source.second] = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (q.size() > 0)
    {
        pair<int, pair<int, int>> front = q.front();
        q.pop();
        int dis = front.first;
        int x = front.second.first;
        int y = front.second.second;
        if (x == destination.first && y == destination.second)
        {
            return dis;
        }

        for (int k = 0; k < 4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1 && dist[newX][newY] > 1 + dis)
            {
                q.push({dis + 1, {newX, newY}});
                dist[newX][newY] = dis + 1;
            }
        }
    }
    return -1;
}
int main()
{

    return 0;
}