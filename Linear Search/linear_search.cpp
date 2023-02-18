#include <bits/stdc++.h>
using namespace std;
// TIME COMPLEXITY OF O(N)
int linearsearch(int arr[], int size, int key);
int main()
{
    cout << "Enter the size of the array" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements in the array" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element you want to search" << endl;
    int key;
    cin >> key;
    int ans = linearsearch(arr, n, key);
    cout << ans << endl;
    return 0;
}
int linearsearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
