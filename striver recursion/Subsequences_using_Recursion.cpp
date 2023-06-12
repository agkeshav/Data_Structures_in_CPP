#include <bits/stdc++.h>
using namespace std;
void subsequences(int index, vector<int> &arr, vector<int> &output, vector<vector<int>> &ans)
{
    if (index >= arr.size())
    {
        ans.push_back(output);
        return;
    }
    subsequences(index + 1, arr, output, ans);
    output.push_back(arr[index]);
    subsequences(index + 1, arr, output, ans);
    output.pop_back();
}
int main()
{
    cout << "Enter the length of the array" << endl;
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<vector<int>> ans;
    vector<int> output;
    subsequences(0, arr, output, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}