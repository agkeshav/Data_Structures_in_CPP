#include <bits/stdc++.h>
using namespace std;
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{

    vector<vector<int>> cost(n, vector<int>(n, 1e9));

    for (auto it : edges)
    {
        cost[it[0]][it[1]] = it[2];
        cost[it[1]][it[0]] = it[2];
    }

    for (int i = 0; i < n; i++)
        cost[i][i] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    int city = INT_MIN;
    int number = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] <= distanceThreshold)
            {
                count++;
            }
        }
        if (number >= count)
        {
            number = count;
            city = i;
        }
    }
    return city;
}
int main()
{

    return 0;
}