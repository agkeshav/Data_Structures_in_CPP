#include <bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q)
{
    // add code here.
    queue<int> ans;
    stack<int> st;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        st.push(a);
    }
    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }
    return ans;
}
void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    print(q);
    q = rev(q);
    print(q);

    return 0;
}