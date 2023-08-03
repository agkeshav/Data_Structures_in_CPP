#include <bits/stdc++.h>
using namespace std;
void reverseQueue(queue<int> &q)
{
    if (q.size() == 0)
        return;

    int num = q.front();
    q.pop();
    reverseQueue(q);
    q.push(num);
}

vector<int> rearrangeQueue(queue<int> &q)
{
    vector<int> ans;
    stack<int> st;
    int n = q.size();
    for (int i = 1; i <= n / 2; i++)
    {
        st.push(q.front());
        q.pop();
    }
    reverseQueue(q);

    while (st.size() > 0)
    {
        q.push(q.front());
        q.pop();
        q.push(st.top());
        st.pop();
    }
    reverseQueue(q);
    while (q.size() > 0)
    {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}
int main()
{

    return 0;
}