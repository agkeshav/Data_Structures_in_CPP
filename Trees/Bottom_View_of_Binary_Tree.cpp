
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
vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> bottomNode;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        Node *frontNode = temp.first;
        int hd = temp.second;
        bottomNode[hd] = frontNode->data;
        q.pop();
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto x:bottomNode){
        ans.push_back(x.second);
    }
    return ans;
}
int main()
{

    Node *root = NULL;
    root = buildTree(root);
    vector<int> ans = bottomView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}