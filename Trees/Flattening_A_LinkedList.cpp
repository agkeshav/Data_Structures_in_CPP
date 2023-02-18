#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *bottom;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << "NULL" << endl;
}
Node *merge(Node *a, Node *b)
{
    Node *ans = new Node(-1);
    Node *temp = ans;
    while (a != NULL &&  b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    while (a != NULL)
    {
        temp->bottom = a;
        temp = temp->bottom;
        a = a->bottom;
    }
    while (b != NULL)
    {
        temp->bottom = b;
        temp = temp->bottom;
        b = b->bottom;
    }

    return ans->bottom;
}
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}
int main()
{
    Node *head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);
    head->next = new Node(10);
    head->next->bottom = new Node(20);
    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);
    head->next->next->next = new Node(28);
    Node *ans = flatten(head);
    print(ans);
    return 0;
}