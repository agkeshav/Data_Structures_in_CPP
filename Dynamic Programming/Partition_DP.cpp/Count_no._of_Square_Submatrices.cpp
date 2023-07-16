#include <bits/stdc++.h>
using namespace std;
int countSquares(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int ans = 0;
    for (int row = 0; row < rows; row++)
    {
        dp[row][0] = matrix[row][0];
        ans += dp[row][0];
    }
    for (int col = 1; col < cols; col++)
    {
        dp[0][col] = matrix[0][col];
        ans += dp[0][col];
    }
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 1)
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            ans += dp[i][j];
        }
    }
    return ans;
}
int main()
{

    return 0;
}