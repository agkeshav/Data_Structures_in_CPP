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
Node *inorderPredecessor(Node *root, int x)
{
    Node *pred = NULL;
    while (root != NULL)
    {
        if (x <= root->data)
        {
            root = root->left;
        }
        else
        {
            pred = root;
            root = root->right;
        }
    }
    return pred;
}
Node *deletefromBST(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        // O child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 Child

        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *pred = inorderPredecessor(root, val);
            int del = pred->data;
            root->data = pred->data;
            root->left = deletefromBST(root->left, del);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deletefromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deletefromBST(root->right, val);
        return root;
    }
}
int main()
{

    return 0;
}