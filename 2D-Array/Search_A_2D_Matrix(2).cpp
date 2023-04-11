#include <bits/stdc++.h>
using namespace std;
// Matrix is row wise sorted as well as column wise sorted
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int rowIndex = 0;
    int colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == target)
        {
            return true;
        }
        else if (element < target)
        {
            rowIndex++;
        }
        else
            colIndex--;
    }
    return false;
}
int main()
{

    return 0;
}