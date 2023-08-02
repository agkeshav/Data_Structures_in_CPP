#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k)
{

    deque<long long int> dq;
    vector<long long> ans;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (dq.size() > 0)
        ans.push_back(arr[dq.front()]);
    else
        ans.push_back(0);

    for (int i = k; i < n; i++)
    {
        if (dq.size() > 0 && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (dq.size() > 0)
            ans.push_back(arr[dq.front()]);
        else
            ans.push_back(0);
    }
    return ans;
}
int main()
{

    return 0;
}