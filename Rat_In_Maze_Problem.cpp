#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> m, vector<vector<int>> visited, int newx, int newy, int n)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (visited[newx][newy] == 0) && (m[newx][newy] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(vector<vector<int>> m, vector<string> &ans, vector<vector<int>> visited, int n, int x, int y, string path)
{
    // base case
    if (x == (n - 1) && y == (n - 1))
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // down
    int newx = x + 1;
    int newy = y;
    if (isSafe(m, visited, newx, newy, n))
    {
        path.push_back('D');
        solve(m, ans, visited, n, newx, newy, path);
        path.pop_back();
    }

    // up
    newx = x - 1;
    newy = y;
    if (isSafe(m, visited, newx, newy, n))
    {
        path.push_back('U');
        solve(m, ans, visited, n, newx, newy, path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y - 1;
    if (isSafe(m, visited, newx, newy, n))
    {
        path.push_back('L');
        solve(m, ans, visited, n, newx, newy, path);
        path.pop_back();
    }

    // right
    newx = x;
    newy = y + 1;
    if (isSafe(m, visited, newx, newy, n))
    {
        path.push_back('R');
        solve(m, ans, visited, n, newx, newy, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here

    vector<string> ans;
    if (m[0][0] == 0)
    {
        return ans;
    }
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";
    solve(m, ans, visited, n, srcx, srcy, path);
    return ans;
}
int main()
{

    return 0;
}