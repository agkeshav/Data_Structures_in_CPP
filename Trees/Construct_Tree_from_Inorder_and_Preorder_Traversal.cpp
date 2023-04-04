#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left=NULL;
        this->right = NULL;
    }
};
int findPosition(int in[], int n, int element, vector<int> &visited)
{

    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
        {
            if (visited[i] == -1)
            {
                visited[i] = 0;
                return i;
            }
        }
    }
    return -1;
}
Node *solve(int in[], int pre[], int &index, int startInorder, int endInorder, int n, vector<int> &visited)
{
    // Base case
    if (index >= n || startInorder > endInorder)
    {
        return NULL;
    }
    int element = pre[index++];
    Node *root = new Node(element);
    int pos = findPosition(in, n, element, visited);
    root->left = solve(in, pre, index, startInorder, pos - 1, n, visited);
    root->right = solve(in, pre, index, pos + 1, endInorder, n, visited);
    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    vector<int> visited; // For duplicate values this vector has been used to check their visited status
    for (int i = 0; i < n; i++)
    {
        visited.push_back(-1);
    }
    int preOrderIndex = 0;
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, visited);
    return ans;
}

int main()
{

    return 0;
}