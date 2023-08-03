#include <bits/stdc++.h>
using namespace std;
string FirstNonRepeating(string A)
{
    // Code here
    string ans = "";
    queue<char> q;
    unordered_map<char, int> mp;
    for (int i = 0; i < A.length(); i++)
    {
        mp[A[i]]++;
        q.push(A[i]);

        if (mp[q.front()] > 1)
        {
            while (q.size() > 0 && mp[q.front()] > 1)
            {
                q.pop();
            }
            if (q.size() == 0)
                ans.push_back('#');
            else
                ans.push_back(q.front());
        }
        else
            ans.push_back(q.front());
    }
    return ans;
}
int main()
{

    return 0;
}