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
void inorder(Node *root, int &i, int k, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, i, k, ans);
    i++;
    if (i == k)
    {
        ans = root->data;
    }
    inorder(root->right, i, k, ans);
}
int kthSmallest(Node *root, int k)
{
    int i = 0;
    int ans = 0;
    inorder(root, i, k, ans);
    return ans;
}
int main()
{

    return 0;
}