#include <bits/stdc++.h>
using namespace std;
void bubblesort(int arr[], int n);
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
    bubblesort(arr, n);
    return 0;
}
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
    printArray(arr, n);
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