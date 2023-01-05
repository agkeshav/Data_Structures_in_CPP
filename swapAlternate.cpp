#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swapAlternate(int arr[], int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        swap(arr[i], arr[i + 1]);
    }
    printArray(arr, size);
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    cout << "Enter the length of the array" << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the numbers in the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    swapAlternate(arr, n);

    return 0;
}