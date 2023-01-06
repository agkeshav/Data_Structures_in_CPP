#include <bits/stdc++.h>
using namespace std;
int findMinimumCost(string str)
{
    // Write your code here
    if (str.length() % 2 == 1)
    {
        return -1;
    }
    else
    {
        stack<char> st;
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (!st.empty())
            {
                if (st.top() == '{' && ch == '}')
                {
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
            else
            {
                st.push(ch);
            }
        }
        // Now stack containing invalid expressions
        int a = 0; // count of open braces
        int b = 0; // count of close braces
        while (!st.empty())
        {
            if (st.top() == '{')
            {
                a++;
            }
            else
            {
                b++;
            }
            st.pop();
        }
        int ans = (a + 1) / 2 + (b + 1) / 2;
        return ans;
    }
}
int main()
{
    string str = "{{{{";
    cout << findMinimumCost(str) << endl;
    return 0;
}