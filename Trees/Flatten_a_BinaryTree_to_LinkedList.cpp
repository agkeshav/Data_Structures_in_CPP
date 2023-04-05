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
void flatten(Node *root)
{
    // Done through Morris Traversal T.C. = O(N) S.C = O(1)
    // code here
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            Node *pred = curr->left;
            while (pred->right != NULL)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
int main()
{

    return 0;
}