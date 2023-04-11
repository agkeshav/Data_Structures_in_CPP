#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // 1,3,5,7,10,11,16,20,23,30,34,60
    int start = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int end = rows * cols - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int element = matrix[mid / cols][mid % cols];
        if (element == target)
        {
            return true;
        }
        else if (element > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return false;
}
int main()
{

    return 0;
}