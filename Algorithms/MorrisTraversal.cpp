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
void visit(Node *root)
{
    cout << root->data << " ";
}
Node *predecessor(Node *root)
{
    Node *pred = root->left;
    while (pred->right != NULL && pred->right != root)
    {
        pred = pred->right;
    }
    return pred;
}
void MorrisTraversal(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            visit(curr);
            curr = curr->right;
        }
        else
        {
            Node *pred = predecessor(curr);
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                visit(curr);
                curr = curr->right;
            }
        }
    }
}
void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout << "Inorder Traversal:- " << endl;
    inorder(root);
    return 0;
}