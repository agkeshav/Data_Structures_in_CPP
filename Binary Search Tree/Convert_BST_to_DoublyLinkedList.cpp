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
Node *convertBSTtoDLL(Node *root, Node *head)
{
    if (root == NULL)
    {
        return NULL;
    }

    convertBSTtoDLL(root->right, head);
    root->right = head;
    if (head->left != NULL)
    {
        head->left = root;
    }
    head = root;
    convertBSTtoDLL(root->left, head);
}
int main()
{

    return 0;
}