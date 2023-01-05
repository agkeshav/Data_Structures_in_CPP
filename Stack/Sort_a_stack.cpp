#include <bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int> &stack, int num){
    if( stack.empty() || stack.top()<num){
        stack.push(num);
        return ;
    }
    int x = stack.top();
    stack.pop();
    sortedInsert(stack,num);
    stack.push(x);
    
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack,num);
    
}
int main()
{
    stack<int> s;
    s.push(3);
    s.push(-7);
    s.push(9);
    s.push(-2);
    s.push(5);
    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}