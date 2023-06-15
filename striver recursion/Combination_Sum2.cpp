#include <bits/stdc++.h>
using namespace std;
void solve(int index, int target, vector<int> &output, vector<vector<int>> &ans, vector<int> &candidates)
{
    if (target == 0)
    {
        ans.push_back(output);
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        if (candidates[i] > target)
        {
            break;
        }
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        output.push_back(candidates[i]);
        solve(i + 1, target - candidates[i], output, ans, candidates);
        output.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(index, target, output, ans, candidates);
    return ans;
}
int main()
{

    return 0;
}