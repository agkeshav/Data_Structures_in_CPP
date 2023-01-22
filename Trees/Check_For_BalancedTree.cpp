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
int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int h1 = height(node->left);
    int h2 = height(node->right);
    int ans = max(h1, h2) + 1;
    return ans;
}
pair<bool, int> isBalancedFast(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool,int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second ) <= 1;

    pair<bool,int> ans = make_pair((leftAns&&rightAns&&diff), max(left.second,right.second)+1 );
    return ans;
}
bool isBalanced(Node *root)
{
    //  Your Code here
    // T.C. = O(N^2)
    if(root == NULL){
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }

    // optimised approach
    // T.C. O(N)
    // pair<bool,int> ans = isBalancedFast(root);
    // return ans.first;
    

}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    cout << isBalanced(root) << endl;

    return 0;
}