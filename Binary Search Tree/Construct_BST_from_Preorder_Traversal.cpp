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
Node *makeBST(vector<int> &preorder, int mini, int maxi, int &index)
{
    if (index >= preorder.size())
    {
        return NULL;
    }
    if (preorder[index] < mini || preorder[index] > maxi)
    {
        return NULL;
    }

    Node *root = new Node(preorder[index++]);
    root->left = makeBST(preorder, mini, root->data, index);
    root->right = makeBST(preorder, root->data, maxi, index);
    return root;
}
Node *bstFromPreorder(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    Node *ans = makeBST(preorder, mini, maxi, i);
    return ans;
}
int main()
{

    return 0;
}