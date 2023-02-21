#include <bits/stdc++.h>
using namespace std;
// Contiguous SubArray with maximum Sum
int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxi = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        // Step1
        sum += nums[i];
        // Step2
        maxi = max(maxi, sum);
        // Step3
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi; // returning the maximum sum
}
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    return 0;
}