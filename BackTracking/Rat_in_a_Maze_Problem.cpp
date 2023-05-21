#include <bits/stdc++.h>
using namespace std;
bool isSafe(int newX, int newY, vector<vector<bool>> &vis, vector<vector<int>> arr, int n)
{
    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && vis[newX][newY] == 0 && arr[newX][newY] == 1)
    {
        return true;
    }
    return false;
}
void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
{

    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // 4 movements D,L,R,U
    // D
    if (isSafe(x + 1, y, visited, arr, n))
    {
        visited[x][y] = true;
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
        visited[x][y] = 0;
    }

    // L
    if (isSafe(x, y - 1, visited, arr, n))
    {
        visited[x][y] = true;
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
        visited[x][y] = 0;
    }
    // R
    if (isSafe(x, y + 1, visited, arr, n))
    {
        visited[x][y] = true;
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
        visited[x][y] = 0;
    }
    // U
    if (isSafe(x - 1, y, visited, arr, n))
    {
        visited[x][y] = true;
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
        visited[x][y] = 0;
    }
}
vector<string> findPath(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    if (arr[0][0] == 0)
    {
        return ans;
    }
    string path = "";
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}
int main()
{

    return 0;
}