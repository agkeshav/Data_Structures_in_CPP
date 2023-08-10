#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, vector<int>> adj;
    vector<int> ans;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    vector<int> visited(numCourses, 0);
    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < numCourses; i++)
    {
        for (auto adjacentNode : adj[i])
        {
            indegree[adjacentNode]++;
        }
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {

            queue<int> q;
            for (int i = 0; i < numCourses; i++)
            {
                if (!visited[i] && indegree[i] == 0)
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }

            while (q.size() > 0)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto adjacentNode : adj[node])
                {
                    indegree[adjacentNode]--;
                    if (indegree[adjacentNode] == 0 && visited[adjacentNode] == 0)
                    {
                        q.push(adjacentNode);
                        visited[adjacentNode] = 1;
                    }
                }
            }
        }
    }
    if (ans.size() == numCourses)
        return ans;
    else
        return {};
}
int main()
{

    return 0;
}