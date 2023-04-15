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
void inorder(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, count);
    count++;
    inorder(root->right, count);
}
bool isCBT(Node *root, int i, int n)
{
    if (root == NULL)
    {
        return true;
    }
    if (i >= n)
    {
        return false;
    }
    bool left = isCBT(root->left, 2 * i + 1, n);
    bool right = isCBT(root->right, 2 * i + 2, n);
    return left && right;
}
bool isCompleteTree(Node *root)
{
    int n = 0;
    inorder(root, n);
    return isCBT(root, 0, n);
}
bool isMaxHeap(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    else if (root->right == NULL)
    {
        return true;
    }
    else if (root->left == NULL)
    {
        return false;
    }
    else
    {
        return (root->data > root->left->data) && (root->data > root->right->data) && isMaxHeap(root->left) && isMaxHeap(root->right);
    }
}
bool isHeap(struct Node *tree)
{
    // code here
    return isCompleteTree(tree) && isMaxHeap(tree);
}
int main()
{

    return 0;
}