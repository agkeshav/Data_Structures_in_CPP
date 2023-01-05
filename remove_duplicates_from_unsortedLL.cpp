#include <iostream>
#include <map>
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
void removeDuplicatesFromUnsortedLL(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        map<int, bool> visited;
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            if (visited[curr->data] == true)
            {
                if (curr->next == NULL)
                {
                    prev->next = NULL;
                    delete curr;
                    return;
                }
                Node *forward = curr;
                Node *curr_next = curr->next;
                prev->next = curr->next;
                delete forward;
                curr = curr_next;
            }
            else
            {
                visited[curr->data] = true;
                prev = curr;
                curr = curr->next;
            }
        }
    }
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
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *node3 = new Node(5);
    node2->next = node3;
    Node *node4 = new Node(4);
    node3->next = node4;
    Node *node5 = new Node(2);
    node4->next = node5;
    Node *node6 = new Node(2);
    node5->next = node6;
    Node *node7 = new Node(4);
    node6->next = node7;
    print(head);
    removeDuplicatesFromUnsortedLL(head);
    print(head);
    return 0;
}