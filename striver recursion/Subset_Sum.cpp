#include <bits/stdc++.h>
using namespace std;
void solve(int idx, int sum, vector<int> &arr, int N, vector<int> &ans)
{
    if (idx == N)
    {
        ans.push_back(sum);
        return;
    }
    // picking
    sum += arr[idx];
    solve(idx + 1, sum, arr, N, ans);
    sum -= arr[idx];
    solve(idx + 1, sum, arr, N, ans);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> ans;
    int idx = 0;
    int sum = 0;
    solve(idx, sum, arr, N, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}