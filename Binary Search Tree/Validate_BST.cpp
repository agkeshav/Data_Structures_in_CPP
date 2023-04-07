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
bool isValid(Node *root, long min, long max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        return isValid(root->left, min, root->data) && isValid(root->right, root->data, max);
    }
    else
    {
        return false;
    }
}
bool isBST(Node *root)
{
    // Your code here
    return isValid(root, LONG_MIN, LONG_MAX);
}
int main()
{

    return 0;
}