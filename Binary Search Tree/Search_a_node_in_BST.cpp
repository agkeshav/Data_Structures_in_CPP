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
bool search(Node *root, int x)
{
    // Your code here
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }

    if (root->data < x)
    {
        return search(root->right, x);
    }
    else
    {
        return search(root->left, x);
    }
}
// Iterative way
bool search(Node *root, int x)
{
    // Your code here
    Node* temp = root;
    while(temp!=NULL){
        if(temp->data ==x ){
            return true;
        }
        else if(temp->data > x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}
int main()
{

    return 0;
}