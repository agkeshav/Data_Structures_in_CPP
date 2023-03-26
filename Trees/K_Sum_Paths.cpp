#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
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
void solve(Node *root, int k, vector<int> path, int &count)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    // left
    solve(root->left, k, path, count);
    // right
    solve(root->right, k, path, count);

    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}
int sumK(Node *root, int k)
{
    // code here
    if (root == NULL)
    {
        return 0;
    }
    vector<int> path;
    int count = 0;
    solve(root, k, path, count);
    return count;
}
int main()
{

    return 0;
}