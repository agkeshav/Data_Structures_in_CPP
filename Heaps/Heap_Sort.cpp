#include <bits/stdc++.h>
using namespace std;
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void HeapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // Step1:
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}
int main()
{
    int arr[6] ={ -1, 70, 60,55,45,50};
    HeapSort(arr,5);
    for(int i=1;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}