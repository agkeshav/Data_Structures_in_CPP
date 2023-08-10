#include<bits/stdc++.h>
using namespace std;
string findOrder(string dict[], int N, int K)
{
    // code here
    string ans = "";
    unordered_map<int, vector<int>> adj;
    for (int k = 0; k < N - 1; k++)
    {
        string a = dict[k];
        string b = dict[k + 1];
        int i = 0, j = 0;
        while (a[i] == b[j])
        {
            i++;
            j++;
        }
        adj[a[i] - 97].push_back(b[i] - 97);
    }
    // topo sort now
    vector<int> visited(K, 0);
    vector<int> indegree(K, 0);
    for (int i = 0; i < K; i++)
    {
        for (auto adjacentNode : adj[i])
        {
            indegree[adjacentNode]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < K; i++)
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
        ans.push_back(node + 97);
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

    return ans;
}
int main(){

return 0;
}