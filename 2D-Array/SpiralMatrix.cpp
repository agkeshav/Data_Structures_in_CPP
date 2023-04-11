#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int total = row * col;
    int cnt = 0;
    int startRow = 0, startCol = 0, endRow = row - 1, endCol = col - 1;
    while (cnt < total)
    {
        // print starting Row
        for (int i = startCol; cnt < total && i <= endCol; i++)
        {
            ans.push_back(matrix[startRow][i]);
            cnt++;
        }
        startRow++;

        // print ending col

        for (int i = startRow; cnt < total && i <= endRow; i++ && cnt < total)
        {
            ans.push_back(matrix[i][endCol]);
            cnt++;
        }
        endCol--;

        // print ending row

        for (int i = endCol; cnt < total && i >= startCol; i-- && cnt < total)
        {
            ans.push_back(matrix[endRow][i]);
            cnt++;
        }
        endRow--;

        // print starting col;
        for (int i = endRow; cnt < total && i >= startRow; i--)
        {
            ans.push_back(matrix[i][startCol]);
            cnt++;
        }
        startCol++;
    }

    return ans;
}
int main()
{

    return 0;
}