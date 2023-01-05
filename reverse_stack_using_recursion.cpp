#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    int x = stack.top();
    stack.pop();
    insertAtBottom(stack, num);
    stack.push(x);
}
void reverseStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, num);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}