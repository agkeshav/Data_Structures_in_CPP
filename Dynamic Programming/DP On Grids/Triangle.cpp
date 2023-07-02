#include <bits/stdc++.h>
using namespace std;
// Recursion
int solve(int i, int j, vector<vector<int>> &triangle)
{
    if (i == triangle.size() - 1)
    {
        return triangle[i][j];
    }

    int down = triangle[i][j] + solve(i + 1, j, triangle);
    int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle);
    return min(down, diagonal);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    // basically we can move down or diagonal
    int m = triangle.size();
    return solve(0, 0, triangle);
}

// Recursion + Memoization
int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == triangle.size() - 1)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + solve(i + 1, j, triangle, dp);
    int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);
    return dp[i][j] = min(down, diagonal);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    // basically we can move down or diagonal
    vector<vector<int>> dp;
    for (int i = 0; i < triangle.size(); i++)
    {
        vector<int> a;
        for (int j = 0; j < triangle[i].size(); j++)
        {
            a.push_back(-1);
        }
        dp.push_back(a);
    }
    return solve(0, 0, triangle, dp);
}

// Tabulation

int minimumTotal(vector<vector<int>> &triangle)
{
    // basically we can move down or diagonal
    vector<vector<int>> dp;
    for (int i = 0; i < triangle.size(); i++)
    {
        vector<int> a;
        for (int j = 0; j < triangle[i].size(); j++)
        {
            a.push_back(-1);
        }
        dp.push_back(a);
    }
    int m = triangle.size();
    for (int i = 0; i < triangle[m - 1].size(); i++)
    {
        dp[m - 1][i] = triangle[m - 1][i];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(diagonal, down);
        }
    }
    return dp[0][0];
}
int main()
{

    return 0;
}