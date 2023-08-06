#include <bits/stdc++.h>
using namespace std;
int max_of_subarrays(vector<int> &arr, int n, int k)
{
    // your code here
    deque<int> maxi(k);
    deque<int> mini(k);
    for (int i = 0; i < k; i++)
    {
        while (maxi.size() > 0 && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (mini.size() > 0 && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    int sum = 0;
    sum += arr[maxi.front()] + arr[mini.front()];
    for (int i = k; i < n; i++)
    {

        // move to next window
        // removal part
        while (maxi.size() > 0 && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (mini.size() > 0 && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // ADDITION
        while (maxi.size() > 0 && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (mini.size() > 0 && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        sum += arr[maxi.front()] + arr[mini.front()];
    }
    return sum;
}
int main()
{
    vector<int> a = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << max_of_subarrays(a, a.size(), k);
    return 0;
}