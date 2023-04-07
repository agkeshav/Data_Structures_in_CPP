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
// Recursive way
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < p->data && root->data < q->data)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    else if (root->data > p->data && root->data > q->data)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else
    {
        return root;
    }
}
// Iterative way
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    while (root != NULL)
    {
        if (root->data < p->data && root->data < q->data)
        {
            root = root->right;
        }
        else if (root->data > p->data && root->data > q->data)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
    return root;
}
int main()
{

    return 0;
}