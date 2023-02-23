#include <bits/stdc++.h>
using namespace std;
vector<int> firstNegativeNumber(vector<int> &arr,int K){
    int i=0,j=0;
    list<int> l;
    vector<int> ans;
    while(j<arr.size()){
        if(arr[j]<0){
            l.push_back(arr[j]);
        }
        if((j-i+1)<K){
            j++;
        }
        else if((j-i+1)==K){
            if(!l.empty()){
                ans.push_back(l.front());
            }
            else{
                ans.push_back(0);
            }
            if(arr[i]<0){
                l.pop_front();
            }
            i++;
        }
        j++;
    }
    return ans;
}
int main()
{

    return 0;
}