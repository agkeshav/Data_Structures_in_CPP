#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<(q.size()-k);i++){
        int a= q.front();
        q.pop();
        q.push(a);
    }
    return q;
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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    print(q);
    q = modifyQueue(q,2);
    print(q);

    return 0;
}