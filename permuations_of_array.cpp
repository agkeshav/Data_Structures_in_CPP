#include <bits/stdc++.h>
using namespace std;
void permutation(vector<int> arr, int index, vector<vector<int> > &ans){
    //base case
    if(index>=arr.size()){
        ans.push_back(arr);
        return; 
    }
    for(int j=index;j<arr.size();j++){
        swap(arr[index],arr[j]);
        permutation(arr,index+1,ans);
        //backtrack
         swap(arr[index],arr[j]);
    }

}
int main()
{
    cout<<"Enter the length of the vector"<<endl;
    int n;cin >> n;
    cout<<"Enter the elements in the vector"<<endl;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int x;cin >> x;
        arr.push_back(x);
    }
    int index = 0;
    vector<vector<int> > ans;
    permutation(arr,index,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}