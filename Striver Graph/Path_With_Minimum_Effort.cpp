#include <bits/stdc++.h>
using namespace std;
int MinimumEffort(vector<vector<int>> &heights)
{
    // Code here
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (pq.size() > 0)
    {
        pair<int, pair<int, int>> front = pq.top();
        int diff = front.first;
        int x = front.second.first;
        int y = front.second.second;
        pq.pop();
        if (x == m - 1 && y == n - 1)
            return diff;
        for (int k = 0; k < 4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n)
            {
                int absDiff = abs(heights[newX][newY] - heights[x][y]);
                int newEffort = max(absDiff, diff);
                if (newEffort < dist[newX][newY])
                {
                    dist[newX][newY] = newEffort;
                    pq.push({newEffort, {newX, newY}});
                }
            }
        }
    }
    return -1;
}
int main()
{

    return 0;
}