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
int height(Node* node){
    if(node == NULL){
        return 0;
    }
    int h1 = height(node->left);
    int h2 = height(node->right);
    int ans = max(h1,h2) + 1;
    return ans;

}
pair<int,int> diamterFast(Node* node){

    // First represents Diameter , Second represents Height
    if(node == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diamterFast(node->left);
    pair<int,int> right = diamterFast(node->right);
    pair<int,int> ans;
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second;

    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second,right.second)+1;
    return ans;
}
int diameter(struct Node *node)
{
    // code here
    if (node == NULL)
    {
        return 0;
    }
    int op1 = diameter(node->left);
    int op2 = diameter(node->right);
    int op3 = height(node->left) + 1+ height(node->right);
    int ans = max(op1,max(op2,op3));
    return ans;

    // second approach
    // return diamterFast(node).first;
}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    cout << diameter(root) << endl;

    return 0;
}