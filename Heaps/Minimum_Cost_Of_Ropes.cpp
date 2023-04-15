#include <bits/stdc++.h>
using namespace std;
long long minCost(long long arr[], long long n)
{
    // Your code here
    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() != 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }

    return ans;
}
int main()
{

    return 0;
}