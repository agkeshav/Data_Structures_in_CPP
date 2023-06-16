#include <bits/stdc++.h>
using namespace std;
// Approach 1
void solve(int index, vector<int> &nums, vector<int> &output, vector<int> &mark, vector<vector<int>> &ans)
{
    if (output.size() == nums.size())
    {
        ans.push_back(output);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (mark[i] == 0)
        {
            output.push_back(nums[i]);
            mark[i] = 1;
            solve(i, nums, output, mark, ans);
            mark[i] = 0;
            output.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> output;
    vector<int> mark(nums.size(), 0);
    vector<vector<int>> ans;
    int index = 0;
    solve(0, nums, output, mark, ans);
    return ans;
}
// --------------------------------------------------------------------------------------------
// Approach 2
void solve(int index, vector<vector<int>> &ans, vector<int> &arr)
{
    if (index >= arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        solve(index + 1, ans, arr);
        swap(arr[index], arr[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(index, ans, nums);
    return ans;
}
int main()
{

    return 0;
}