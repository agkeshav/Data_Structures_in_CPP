#include <bits/stdc++.h>
using namespace std;
bool knows(vector<vector<int>> M, int a, int b)
{
    if (M[a][b] == 1)
    {
        return true;
    }
    return false;
}
int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (knows(M, a, b))
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }
    int ans = st.top();
    int zeroCount = 0;
    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount != n)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount != n - 1)
    {
        return -1;
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> M;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            M[i].push_back(x);
        }
    }
    cout << celebrity(M, n) << endl;
}
