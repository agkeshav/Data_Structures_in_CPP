#include <bits/stdc++.h>
using namespace std;
void shortest_distance(vector<vector<int>> &cost)
{
    // Code here
    int n = cost.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cost[i][j] = 0;
            else if (cost[i][j] == -1)
            {
                cost[i][j] = 1e9;
            }
        }
    }
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (cost[i][i] < 0)
        {
            cout << "Negative cycle Present" << endl;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] == 1e9)
                cost[i][j] = -1;
        }
    }
}
int main()
{

    return 0;
}