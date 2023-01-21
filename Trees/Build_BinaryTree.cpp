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

Node* buildTree(Node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data for the left node of the root "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for the right node of the root "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(Node* root){
    queue<Node*> q; 
    q.push(root);
    q.push(NULL); // NULL is used for so that we can get know when a level is finished.
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                // queue has still some child Node
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    } 
}
void inorder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void buildFromLevelOrderTraversal(Node* &root){
    queue<Node*> q;

    int data;
    cout<<"Enter the data of the root node "<<endl;
    cin >> data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter the data for the left of the "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter the data for the right of the "<<temp->data<<endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     Node* root = NULL;
    // root = buildTree(root);
    // cout << "Level Order Traversal is:- " << endl;
    // levelOrderTraversal(root);
    // cout<<"Inorder Traversal is:- "<<endl;
    // inorder(root);
    // cout<<endl;
    // cout<<"PreOrder Traversal is:- "<<endl;
    // preorder(root);
    // cout<<endl;
    // cout<<"PostOrder Traversal is:- "<<endl;
    // postOrder(root);
    // cout<<endl;
    buildFromLevelOrderTraversal(root);
    levelOrderTraversal(root);


    return 0;
}