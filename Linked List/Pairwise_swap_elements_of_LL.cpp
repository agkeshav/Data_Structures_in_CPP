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
Node *pairWiseSwap(struct Node *head)
{
    // The task is to complete this method
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    int k = 0;
    Node *next = NULL;
    while (k < 2)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        k++;
    }
    head->next = pairWiseSwap(next);
    return prev;
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
    head = pairWiseSwap(head);
    print(head);

    return 0;
}