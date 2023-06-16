#include <bits/stdc++.h>
using namespace std;
// Question statement
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

void solve(int idx, vector<int> &nums, vector<int> &output, vector<vector<int>> &ans)
{
    ans.push_back(output);
    for (int i = idx; i < nums.size(); i++)
    {
        if (i > idx && nums[i] == nums[i - 1])
            continue;
        output.push_back(nums[i]);
        solve(i + 1, nums, output, ans);
        output.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int idx = 0;
    vector<int> output;
    solve(idx, nums, output, ans);
    return ans;
}
int main()
{

    return 0;
}