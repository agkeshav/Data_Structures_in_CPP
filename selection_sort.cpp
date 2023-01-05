#include <bits/stdc++.h>
using namespace std;
void selectionsort(int arr[], int n);
int getMinIndex(int arr[], int n, int start, int end);
void swap(int *a, int *b);
void printArray(int arr[], int n);
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
    cout << "Sorted array is " << endl;
    selectionsort(arr, n);
    return 0;
}
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int start = i;
        int end = n - 1;
        int minIndex = getMinIndex(arr, n, start, end);
        swap(&arr[i], &arr[minIndex]);
    }
    printArray(arr, n);
}
int getMinIndex(int arr[], int n, int start, int end)
{
    int min = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < arr[start])
        {
            min = i;
        }
    }
    return min;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}