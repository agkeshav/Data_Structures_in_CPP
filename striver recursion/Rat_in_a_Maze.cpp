#include <bits/stdc++.h>
using namespace std;
void solve(int x, int y, int di[], int dj[], string &path, vector<string> &ans, vector<vector<int>> &m,
           int n, vector<vector<int>> &visited)
{

    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = x + di[ind];
        int nextj = y + dj[ind];
        if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && visited[nexti][nextj] == 0 && m[nexti][nextj] == 1)
        {
            visited[x][y] = 1;
            path.push_back(dir[ind]);
            solve(nexti, nextj, di, dj, path, ans, m, n, visited);
            path.pop_back();
            visited[x][y] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> ans;
    // D,L,R,U
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    string path = "";
    vector<vector<int>> visited(n, vector<int>(n, 0));
    if (m[0][0] == 1)
        solve(0, 0, di, dj, path, ans, m, n, visited);
    return ans;
}
int main()
{

    return 0;
}