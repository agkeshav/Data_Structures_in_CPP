#include <bits/stdc++.h>
using namespace std;
void solve(int index, int sum, vector<vector<int>> &ans, vector<int> &candidates, vector<int> &output, int target)
{
    if (sum > target)
    {
        return;
    }
    if (index == candidates.size())
    {
        if (sum == target)
        {
            ans.push_back(output);
        }
        return;
    }
    // picking
    output.push_back(candidates[index]);
    sum += candidates[index];
    solve(index, sum, ans, candidates, output, target);
    sum -= candidates[index];
    output.pop_back();

    // not picking
    solve(index + 1, sum, ans, candidates, output, target);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    int sum = 0;
    solve(index, sum, ans, candidates, output, target);
    return ans;
}
int main()
{

    return 0;
}