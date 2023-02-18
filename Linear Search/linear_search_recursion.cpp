#include <iostream>
using namespace std;
bool linearSearch(int arr[],int n,int target){
    if(n==0){
        return false;
    }
    if(arr[0]==target){
        return true;
    }
    else{
        bool ans = linearSearch(arr+1,n-1,target);
        return ans;
    }
}
int main()
{
    cout << "Enter the length of the array" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements in the array" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter the element to search"<<endl;
    int target;cin>>target;
    bool ans = linearSearch(arr,n,target);
    if(ans){
        cout<<"Element Found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}