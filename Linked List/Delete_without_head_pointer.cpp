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
void deleteNode(Node *del)
{
    // Your code here
    // Copy the data of the next node into the delete Node then delete the next node.
    Node *next = del->next;
    del->data = next->data;
    del->next = next->next;
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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    print(head);
    deleteNode(head->next->next);
    print(head);

    return 0;
}