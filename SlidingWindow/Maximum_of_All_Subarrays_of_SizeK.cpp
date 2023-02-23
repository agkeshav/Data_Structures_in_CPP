#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    list<int> l;
    int i=0,j=0;
    while(j<nums.size()){
       while(l.size()>0 && l.back()<nums[j]){
        l.pop_back();
       }
       l.push_back(nums[j]);
        if((j-i+1)<k){
            j++;
        }
        else if((j-i+1)==k){
            ans.push_back(l.front());
            if(nums[i]==l.front()){
                l.pop_front();
            }
            i++;
            j++;
        }
    }  
    return ans;
}
int main()
{
    vector<int> nums = { 1,-1 }; 
    int k = 1;
    vector<int>ans = maxSlidingWindow(nums,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}