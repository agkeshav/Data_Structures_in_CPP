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
Node* inorderPredecessor(Node *root, int x)
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
Node* inorderSuccessor(Node *root, int x)
{
    Node* succ = NULL;
    while(root!=NULL){
        if(x>=root->data){
            root = root->right;
        }
        else{
            succ = root;
            root = root->left;
        }
    }
    return succ;
    
}
int main()
{

    return 0;
}