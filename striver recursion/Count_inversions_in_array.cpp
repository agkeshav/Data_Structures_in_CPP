#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &a, int start, int mid, int end)
{
    int cnt = 0;
    vector<int> temp;
    int left = start;
    int right = mid + 1;
    while (left <= mid && right <= end)
    {
        if (a[left] <= a[right])
        {
            // left element is smaller
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            // right is smaller
            // here the inversions will come
            cnt += (mid - left + 1);
            temp.push_back(a[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }

    while (right <= end)
    {
        temp.push_back(a[right]);
        right++;
    }
    for (int i = start; i <= end; i++)
    {
        a[i] = temp[i - start];
    }

    return cnt;
}
int mergeSort(vector<int> &a, int start, int end)
{
    if (start >= end)
        return 0;

    int cnt = 0;
    int middle = (start) + (end - start) / 2;
    cnt += mergeSort(a, start, middle);
    cnt += mergeSort(a, middle + 1, end);
    cnt += merge(a, start, middle, end);
    return cnt;
}
int main()
{
    vector<int> v = {5, 3, 2, 4, 1};
    cout << mergeSort(v, 0, v.size() - 1);
    return 0;
}