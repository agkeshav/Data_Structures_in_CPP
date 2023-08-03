#include <bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        balance += gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += balance;
            balance = 0;
            start = i + 1;
        }
    }
    if (deficit + balance >= 0)
        return start;
    else
        return -1;
}
int main()
{

    return 0;
}