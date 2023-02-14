
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
vector<int> topView(Node *root)
{
    // Your code here
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> topNode;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        Node* frontNode = temp.first;
        int hd = temp.second;
        q.pop();
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));

        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }

    }
    for(auto x:topNode){
        ans.push_back(x.second);
    }
    return ans;
}
int main()
{

    Node *root = NULL;
    root = buildTree(root);
    vector<int> ans = topView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}