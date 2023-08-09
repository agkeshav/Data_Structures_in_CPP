#include <bits/stdc++.h>
using namespace std;
bool isBipartite(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (q.size() > 0)
            {
                int node = q.front();
                int col = color[node];
                q.pop();
                for (auto it : graph[node])
                {
                    if (color[it] == -1)
                    {
                        q.push(it);
                        color[it] = !col;
                    }
                    else if (color[it] != -1 && color[node] == color[it])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main()
{

    return 0;
}