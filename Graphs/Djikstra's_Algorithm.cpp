#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V, INT_MAX);

    dist[S] = 0;
    set<pair<int, int>> st; // first denotes the distance of node and second denotes that node
    st.insert(make_pair(0, S));
    while (st.size() != 0)
    {
        auto top = *(st.begin());

        int dis = top.first;
        int node = top.second;
        st.erase(*st.begin());
        for (auto neighbour : adj[node])
        {
            if (dis + neighbour[1] < dist[neighbour[0]])
            {
                auto record = st.find(make_pair(dist[neighbour[0]], neighbour[0]));
                if (record != st.end())
                {
                    st.erase(record);
                }
                dist[neighbour[0]] = dis + neighbour[1];
                st.insert(make_pair(dist[neighbour[0]], neighbour[0]));
            }
        }
    }
    return dist;
}
int main()
{

    return 0;
}