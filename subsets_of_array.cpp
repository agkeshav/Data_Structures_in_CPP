#include <bits/stdc++.h>
using namespace std;
void subsets(vector<int> arr, int index, vector<int> output,vector<vector<int> >&ans ){
    //base case
    if(index>=arr.size()){
        ans.push_back(output);
        return;
    }
    // exclude call
    subsets(arr,index+1,output,ans);
    //include call
    int element = arr[index];
    output.push_back(element);
    subsets(arr,index+1,output,ans);
    
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
    vector<int> output;
    vector<vector<int> > ans;
    subsets(arr,index,output,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}