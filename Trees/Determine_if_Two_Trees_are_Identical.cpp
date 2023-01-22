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

bool isIdentical(Node *r1, Node *r2)
{
    // Your Code here
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if ((r1 == NULL && r2 != NULL) || (r2 == NULL && r1 != NULL))
    {
        return false;
    }
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool value = r1->data == r2->data;
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    

    return 0;
}