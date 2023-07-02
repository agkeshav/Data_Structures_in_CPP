#include <bits/stdc++.h>
using namespace std;
// Recursion
int solve(int index, int last, vector<vector<int>> &points)
{
    if (index == 0)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < points[0].size(); i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    int maxi = INT_MIN;
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {
            maxi = max(maxi, points[index][i] + solve(index - 1, i, points));
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return solve(n - 1, 3, points);
}

// Recursion + Memoization
int solve(int index, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < points[0].size(); i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[index][last] != -1)
        return dp[index][last];
    int maxi = INT_MIN;
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {
            maxi = max(maxi, points[index][i] + solve(index - 1, i, points, dp));
        }
    }
    return dp[index][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int days = points.size();
    // 4 different values of last
    int last = points[0].size();
    vector<vector<int>> dp(days, vector<int>(last + 1, -1));
    solve(days - 1, 3, points, dp);

    return dp[days - 1][3];
}

// Tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int days = points.size();
    // 4 different values of last
    int last = points[0].size();
    vector<vector<int>> dp(days, vector<int>(last + 1, -1));
    for (int i = 0; i < 4; i++)
    {
        int maxi = INT_MIN;
        for (int j = 0; j <= 2; j++)
        {
            if (i != j)
                maxi = max(maxi, points[0][j]);
        }
        dp[0][i] = maxi;
    }
    for (int day = 1; day <= days - 1; day++)
    {
        for (int last = 0; last <= 3; last++)
        {
            int maxi = INT_MIN;
            for (int task = 0; task < 3; task++)
            {
                if (last != task)
                    maxi = max(maxi, points[day][task] + dp[day - 1][task]);
            }
            dp[day][last] = maxi;
        }
    }
    return dp[days-1][3];
}
// Space optimised
int ninjaTraining(int n, vector<vector<int>> &points)
{

    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {

        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }

        prev = temp;
    }

    return prev[3];
}
int main()
{

    return 0;
}