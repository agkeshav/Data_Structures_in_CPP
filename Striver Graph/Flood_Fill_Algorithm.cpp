#include <bits/stdc++.h>
using namespace std;
bool possible(int i, int j, vector<vector<int>> &image, vector<vector<int>> &visited, int color)
{
    return (i >= 0 && i < image.size() && j >= 0 && j < image[0].size() && visited[i][j] == 0 && image[i][j] == color);
}
void solve(vector<vector<int>> &image, int sr, int sc, int color, int newColor, vector<vector<int>> &visited, vector<vector<int>> &ans)
{
    visited[sr][sc] = true;
    ans[sr][sc] = newColor;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, +1, -1};
    for (int k = 0; k < 4; k++)
    {
        int newX = sr + dx[k];
        int newY = sc + dy[k];
        if (possible(newX, newY, image, visited, color))
        {
            solve(image, newX, newY, color, newColor, visited, ans);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // Code here
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> ans = image;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int sColor = image[sr][sc];
    solve(image, sr, sc, sColor, newColor, visited, ans);
    return ans;
}
int main()
{

    return 0;
}