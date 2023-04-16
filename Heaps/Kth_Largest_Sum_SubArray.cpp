#include <bits/stdc++.h>
using namespace std;
int kthLargest(vector<int> &Arr, int N, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += Arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
int main()
{

    return 0;
}