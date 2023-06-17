#include <bits/stdc++.h>
using namespace std;
void solve(int fact, vector<int> &numbers, int k, int n, string &ans)
{
    if (numbers.size() == 0)
    {
        return;
    }
    ans.push_back(numbers[k / fact] + '0');
    numbers.erase(numbers.begin() + k / fact);
    if (numbers.size() != 0)
        solve(fact / numbers.size(), numbers, k % fact, n, ans);
}
string getPermutation(int n, int k)
{
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    solve(fact, numbers, k - 1, n, ans);
    return ans;
}
int main()
{

    return 0;
}