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
void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
bool findTarget(Node *root, int k)
{
    vector<int> ans;
    inorder(root, ans);
    int i = 0, j = ans.size() - 1;
    while (i < j)
    {
        if (ans[i] + ans[j] == k)
        {
            return true;
        }
        else if (ans[i] + ans[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
int main()
{

    return 0;
}