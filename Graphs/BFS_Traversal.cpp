#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{

public:
    unordered_map<T, vector<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        // direction 0 means undirected graph
        // direction 1 means directed graph

        // Create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto x : adj)
        {
            cout << x.first << " ->";
            for (auto j : x.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
    void bfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while (!q.empty())
        {
            ans.push_back(q.front());
            int temp = q.front();
            q.pop();
            for (auto x : adj[temp])
            {
                if (visited[x] == false)
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
    void printBFS()
    {
        vector<int> ans;
        cout << "Enter the number of vertex" << endl;
        int n;
        cin >> n;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bfs(adj, visited, ans, i);
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 8, 0);
    g.addEdge(1, 6, 0);
    g.addEdge(1, 7, 0);
    g.addEdge(1, 8, 0);
    g.addEdge(5, 8, 0);
    g.addEdge(6, 0, 0);
    g.addEdge(7, 3, 0);
    g.addEdge(7, 4, 0);
    g.addEdge(8, 7, 0);
    g.addEdge(2, 5, 0);
    g.printAdjList();
    g.printBFS();
    return 0;
}
