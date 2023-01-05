#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *sort012(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;
    Node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            zeroTail->next = curr;
            zeroTail = curr;
        }
        else if (value == 1)
        {
            oneTail->next = curr;
            oneTail = curr;
        }
        else if (value == 2)
        {
            twoTail->next = curr;
            twoTail = curr;
        }
        curr = curr->next;
    }
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    delete oneHead;
    if (twoHead->next != NULL)
    {
        oneTail->next = twoHead->next;
    }
    else
    {
        oneTail->next = NULL;
    }
    delete twoHead;
    twoTail->next = NULL;
    head = zeroHead->next;
    delete zeroHead;
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *node2 = new Node(0);
    node1->next = node2;
    Node *node3 = new Node(2);
    node2->next = node3;
    Node *node4 = new Node(1);
    node3->next = node4;
    Node *node5 = new Node(2);
    node4->next = node5;
    print(head);
    head = sort012(head);
    print(head);
    return 0;
}