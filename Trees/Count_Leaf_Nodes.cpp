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
void inorder(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    inorder(root->right, count);
}
int countLeafNodes(Node *root)
{
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    cout << countLeafNodes(root) << endl;

    return 0;
}