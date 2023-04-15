#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here
    // Step1 merge both the vectors;
    vector<int> merge;
    for (int i = 0; i < n; i++)
    {
        merge.push_back(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        merge.push_back(b[i]);
    }

    // Build heap
    for (int i = merge.size() / 2 - 1; i >= 0; i--)
    {
        heapify(merge, merge.size(), i);
    }

    return merge;
}
int main()
{

    return 0;
}