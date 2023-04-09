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
void inorder(Node *root, vector<int> &inorderVector)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, inorderVector);
    inorderVector.push_back(root->data);
    inorder(root->right, inorderVector);
}
Node *makeBalanceBST(vector<int> &inorderVector, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    Node *newNode = new Node(inorderVector[mid]);
    newNode->left = makeBalanceBST(inorderVector, start, mid - 1);
    newNode->right = makeBalanceBST(inorderVector, mid + 1, end);
    return newNode;
}
Node *balanceBST(Node *root)
{
    vector<int> inorderVector;
    inorder(root, inorderVector);
    Node *ans = makeBalanceBST(inorderVector, 0, inorderVector.size() - 1);
    return ans;
}
int main()
{

    return 0;
}