#include <bits/stdc++.h>
using namespace std;
void subsequences(int index, int sum, int k, vector<int> &arr, vector<vector<int>> &ans, vector<int> &output)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            ans.push_back(output);
        }
        return;
    }

    // picking the element
    output.push_back(arr[index]);
    sum += arr[index];
    subsequences(index + 1, sum, k, arr, ans, output);
    sum -= arr[index];
    output.pop_back();

    // not picking the element
    subsequences(index + 1, sum, k, arr, ans, output);
}

bool printOneSubsequence(int index, int sum, int k, vector<int> &arr, vector<int> &output)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            for (auto it : output)
                cout << it << " ";
            return true;
        }
        return false;
    }

    // picking the element
    output.push_back(arr[index]);
    sum += arr[index];
    if (printOneSubsequence(index + 1, sum, k, arr, output) == true)
    {
        return true;
    }
    sum -= arr[index];
    output.pop_back();

    // not picking the element
    if (printOneSubsequence(index + 1, sum, k, arr, output) == true)
    {
        return true;
    }
    return false;
}
int countSubsequence(int index, int sum, int k, vector<int> &arr)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }
    sum += arr[index];
    int l = countSubsequence(index + 1, sum, k, arr);
    sum -= arr[index];
    int r = countSubsequence(index + 1, sum, k, arr);
    return l + r;
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
    cout << "Enter the target" << endl;
    int k;
    cin >> k;
    vector<vector<int>> ans;
    vector<int> output;
    // subsequences(0, 0, k, arr, ans, output);
    // cout << "Printing all the subsequences with sum k ->" << endl;
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "Printing one subsequence with sum k ->" << endl;
    // printOneSubsequence(0, 0, k, arr, output);

    cout << "Number of subsequences with sum equal to k -> " << countSubsequence(0, 0, k, arr) << endl;
    return 0;
}