#include <bits/stdc++.h>
using namespace std;
string reverse(string str){
    stack<char> st;
    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    }
    string ans = "";
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    string str = "nirmika";
    cout<<reverse(str)<<endl;
    return 0;
}