
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
void traverseLeft(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right==NULL){
        return ;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }

}
void traverseLeaf(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}
void traverseRight(Node* root, vector<int> &ans){
    if(root==NULL  || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->left,ans);
    }
    ans.push_back(root->data);
}
vector<int> boundary(Node *root)
{
    // Your code here
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);

    // left part print/ store
    traverseLeft(root->left,ans);

    //Traverse Leaf Nodes for left Subtree
    traverseLeaf(root->left,ans);

    // Traverse Leaf Nodes for right Subtree

    traverseLeaf(root->right,ans);

    // Traverse Right Subtree in reverse Order
    traverseRight(root->right,ans);

    return ans;

}
int main()
{

    Node *root = NULL;
    root = buildTree(root);
    vector<int> ans = boundary(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}