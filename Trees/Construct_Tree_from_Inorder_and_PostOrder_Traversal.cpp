#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
int findPosition(int in[], int n, int element, vector<int> &visited)
{

    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
        {
            if (visited[i] == -1)
            {
                visited[i] = 0;
                return i;
            }
        }
    }
    return -1;
}
Node *solve(int in[], int post[], int &index, int startInorder, int endInorder, int n, vector<int> &visited)
{
    // Base case
    if (index < 0 || startInorder > endInorder)
    {
        return NULL;
    }
    int element = post[index--];
    Node *root = new Node(element);
    int pos = findPosition(in, n, element, visited);
    root->right = solve(in, post, index, pos + 1, endInorder, n, visited);
    root->left = solve(in, post, index, startInorder, pos - 1, n, visited);
    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    vector<int> visited;
    for (int i = 0; i < n; i++)
    {
        visited.push_back(-1);
    }
    int postOrderIndex = n - 1;
    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n, visited);
    return ans;
}
int main()
{

    return 0;
}