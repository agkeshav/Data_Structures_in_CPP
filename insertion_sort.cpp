#include <bits/stdc++.h>
using namespace std;
void insertionsort(int arr[], int n);
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
    insertionsort(arr, n);
    return 0;
}
void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && current < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    printArray(arr, n);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}