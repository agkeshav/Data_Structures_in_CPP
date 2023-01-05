#include <bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        // for opening bracket'
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            // for closing bracket
            if (!s.empty())
            {
                char c = s.top();
                if ((c == '(' && ch == ')') ||
                    (c == '{' && ch == '}') ||
                    (c == '[' && ch == ']'))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string str = "(({))";
    cout<<isValidParenthesis(str)<<endl;
    return 0;
}