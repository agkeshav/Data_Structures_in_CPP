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
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
    }
    newNode->next = head;
    head = newNode;
}
void insertAtLast(Node* &tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}
void insertInBetween(Node* &head, Node* &tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *newNode = new Node(data);
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtLast(tail, data);
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(Node* &head, int position)
{
    if (position == 1)
    { // deleting head node
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    { // deletion from between and last
        Node *current = head;
        Node *previous = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            previous = current;
            current = current->next;
            cnt++;
        }
        previous->next = current->next;
        delete current;
    }
}
void print(Node* &head)
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
    Node *newNode = new Node(10);
    Node *head = newNode;
    Node *tail = newNode;
    print(head);
    insertAtHead(head, 12);
    insertAtHead(head, 15);
    insertAtLast(tail, 40);
    insertInBetween(head, tail, 11, 3);
    deleteNode(head, 1);
    deleteNode(head, 3);
    print(head);
    return 0;
}