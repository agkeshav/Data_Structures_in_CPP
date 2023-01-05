#include <iostream>
using namespace std;
bool isSorted(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans = isSorted(arr+1,n-1);
        return ans;
    }
}
int main()
{
    cout<<"Enter the length of the array"<<endl;
    int n;cin>>n;
    cout<<"Enter the elements in the array"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool ans = isSorted(arr,n);
    if(ans){
        cout<<"Array is Sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    return 0;
}