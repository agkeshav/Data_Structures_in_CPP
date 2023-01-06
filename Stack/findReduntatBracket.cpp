#include <bits/stdc++.h>
using namespace std;
bool ReduntantBracket(string &s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='(' || ch == '+' || ch=='-' || ch == '*' || ch=='/'){
            st.push(ch);
        }
        else{
            // for closing bracket or lowercase
            if(ch==')'){
                bool isReduntant  = true;
                while(st.top()!='('){
                    char top = st.top();
                    if(top == '+' || top=='-' || top == '*' || top=='/'){
                        isReduntant = false;
                    }
                    st.pop();
                }
                if(isReduntant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
int main()
{   
    string s = "(a+b)";
    cout<<ReduntantBracket(s)<<endl;
    return 0;
}