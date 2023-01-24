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
pair<bool, int> isSum(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> left = isSum(root->left);
    pair<bool, int> right = isSum(root->right);
    bool currData = (left.second + right.second) == root->data;
    pair<bool, int> ans;
    ans = make_pair((left.first && right.first && currData), 2 * root->data);
    return ans;
}
bool isSumTree(Node *root)
{
    // 10 20 10 -1 -1 10 -1 -1 30 -1 -1
    // Your code here
    if (root == NULL)
    {
        return true;
    }
    pair<bool, int> ans = isSum(root);
    return ans.first;
}
int main()
{

    Node *root = NULL;
    root = buildTree(root);
    cout << isSumTree(root) << endl;

    return 0;
}