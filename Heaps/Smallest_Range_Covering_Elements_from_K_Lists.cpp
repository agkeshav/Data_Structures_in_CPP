#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    int row;
    int col;

public:
    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        pair<int, int> p;
        vector<int> ans;

        int maxi = INT_MIN;
        int mini = INT_MAX;
        priority_queue<Node *, vector<Node *>, compare> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(new Node(nums[i][0], i, 0));
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
        }
        int start = mini;
        int end = maxi;
        p.first = start;
        p.second = end;
        while (!pq.empty())
        {
            Node *topNode = pq.top();
            int mini = topNode->data;
            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
                p.first = start;
                p.second = end;
            }
            pq.pop();
            if (topNode->col < nums[topNode->row].size() - 1)
            {
                maxi = max(maxi, nums[topNode->row][topNode->col + 1]);
                pq.push(new Node(nums[topNode->row][topNode->col + 1], topNode->row, topNode->col + 1));
            }
            else
            {
                break;
            }
        }
        ans.push_back(p.first);
        ans.push_back(p.second);
        return ans;
    }
};
int main(){

return 0;
}