#include <iostream>
using namespace std;
void quickSort(int arr[], int start, int end){
    
}
int main()
{
    cout << "Enter the length of the array" << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}