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
// Approach 1 merge both the inorders of BSTs in sorted way and then make the final BST from that merged vector
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
vector<int> merge(vector<int> inorder1, vector<int> inorder2)
{
    if (inorder1.size() == 0)
    {
        return inorder2;
    }
    if (inorder2.size() == 0)
    {
        return inorder1;
    }
    vector<int> ans;
    int i = 0, j = 0;
    while (i < inorder1.size() && j < inorder2.size())
    {
        if (inorder1[i] < inorder2[j])
        {
            ans.push_back(inorder1[i]);
            i++;
        }
        else
        {
            ans.push_back(inorder2[j]);
            j++;
        }
    }
    while (i < inorder1.size())
    {
        ans.push_back(inorder1[i]);
        i++;
    }
    while (j < inorder2.size())
    {
        ans.push_back(inorder2[j]);
        j++;
    }

    return ans;
}
Node *inorderToBST(vector<int> &finalInorder, int start, int end)
{
    if (finalInorder.size() == 0)
    {
        return NULL;
    }
    if (start > end)
    {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    Node *root = new Node(finalInorder[mid]);
    root->left = inorderToBST(finalInorder, start, mid - 1);
    root->right = inorderToBST(finalInorder, mid + 1, end);
    return root;
}
Node *mergeBST(Node *root1, Node *root2)
{
    // Write your code here.
    vector<int> inorder1;
    vector<int> inorder2;
    inorder(root1, inorder1);
    inorder(root2, inorder2);

    vector<int> finalInorder = merge(inorder1, inorder2);

    return inorderToBST(finalInorder, 0, finalInorder.size() - 1);
}
int main()
{

    return 0;
}