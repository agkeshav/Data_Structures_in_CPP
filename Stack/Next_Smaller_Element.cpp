#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n){
    vector<int> ans;
    stack<int> st;
    st.push(-1);
    for(int i=arr.size()-1;i>=0;i--){
        int num = st.top();
        int curr = arr[i];
        if(num<curr){
            ans.push_back(num);
            st.push(curr);
        }
        else{
            while(st.top()>=curr){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(curr);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
int main()
{
    vector<int> a;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    
    vector<int> ans = nextSmallerElement(a,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}