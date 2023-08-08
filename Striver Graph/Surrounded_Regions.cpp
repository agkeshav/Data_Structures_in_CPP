#include <bits/stdc++.h>
using namespace std;
bool possible(int i, int j, vector<vector<char>> &board, vector<vector<int>> &visited)
{
    int m = board.size();
    int n = board[0].size();
    return (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 0 && board[i][j] == 'O');
}
void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &visited, vector<int> &dx, vector<int> &dy)
{
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int newX = i + dx[k];
        int newY = j + dy[k];
        if (possible(newX, newY, board, visited))
        {
            dfs(newX, newY, board, visited, dx, dy);
        }
    }
}
void solve(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();
    vector<int> dx = {-1, +1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        if (visited[i][0] == 0 && board[i][0] == 'O')
        {
            dfs(i, 0, board, visited, dx, dy);
        }
        if (visited[i][n - 1] == 0 && board[i][n - 1] == 'O')
        {
            dfs(i, n - 1, board, visited, dx, dy);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[0][i] == 0 && board[0][i] == 'O')
        {
            dfs(0, i, board, visited, dx, dy);
        }
        if (visited[m - 1][i] == 0 && board[m - 1][i] == 'O')
        {
            dfs(m - 1, i, board, visited, dx, dy);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                board[i][j] = 'X';
            }
        }
    }
}
int main()
{

    return 0;
}