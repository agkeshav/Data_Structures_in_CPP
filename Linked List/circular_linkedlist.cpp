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
// There is not much use of head in the CLL we will be using tail here.
void insertNode(Node *&tail, int element, int data)
{

    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *current = tail;
        while (current->data != element)
        {
            current = current->next;
        }
        Node *temp = new Node(data);
        temp->next = current->next;
        current->next = temp;
    }
}
void print(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << "->";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
void deleteNode(Node *tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    //1 node linked list
    if(curr == prev){
        tail = NULL;
        return;
    }
    if (tail == curr)
    {
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 3, 9);
    print(tail);
    deleteNode(tail, 5);
    print(tail);
    deleteNode(tail, 9);
    print(tail);
    deleteNode(tail, 7);
    print(tail);
    deleteNode(tail, 3);
    print(tail);

    return 0;
}