#include <bits/stdc++.h>
using namespace std;
const int mod = 100000;
int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // code here
    vector<int> dist(mod, 1e9);
    pair<int, int> src = {start, 0};
    queue<pair<int, int>> pq;
    pq.push(src);
    while (pq.size() > 0)
    {
        pair<int, int> front = pq.front();
        int node = front.first;
        int dis = front.second;
        if (node == end)
            return dis;
        pq.pop();
        for (int i = 0; i < arr.size(); i++)
        {
            int n = (node * arr[i]) % mod;
            if (dist[n] > dis + 1)
            {
                dist[n] = dis + 1;
                pq.push({n, dist[n]});
            }
        }
    }
    if (dist[end] == 1e9)
        return -1;
    else
        return dist[end];
}
int main()
{

    return 0;
}