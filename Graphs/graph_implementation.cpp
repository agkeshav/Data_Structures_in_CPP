#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{

public:
    unordered_map<T, list<T>> adj;

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
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 4, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 0);
    g.printAdjList();
    return 0;
}