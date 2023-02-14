
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
void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    // We entered in the next level
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}
vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    solve(root, ans, 0);
}
int main()
{

    Node *root = NULL;
    root = buildTree(root);
    vector<int> ans = rightView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}