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

void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}
Node *fillPreOrder(Node *root, vector<int> &inorder, int &index)
{
    if (root == NULL)
    {
        return NULL;
    }
    int element = inorder[index++];
    Node *ans = new Node(element);

    ans->left = fillPreOrder(root->left, inorder, index);
    ans->right = fillPreOrder(root->right, inorder, index);
    return ans;
}
Node *convertBST(Node *root)
{

    vector<int> inorder;
    inorderTraversal(root, inorder);
    int index = 0;
    return fillPreOrder(root, inorder, index);
}
int main()
{

    return 0;
}