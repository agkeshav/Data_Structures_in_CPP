#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
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

Node *buildTree(Node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data for the left node of the root " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for the right node of the root " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> leftPair = solve(root->left);
    pair<int, int> rightPair = solve(root->right);
    pair<int, int> ans;
    ans.first = root->data + leftPair.second + rightPair.second;
    ans.second = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);
    return ans;
}
int getMaxSum(Node *root)
{
    // Add your code here
    if (root == NULL)
    {
        return 0;
    }
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}
int main()
{

    return 0;
}