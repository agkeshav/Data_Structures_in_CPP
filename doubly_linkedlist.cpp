#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insertAtHead(Node *&head, int data)
{
     Node *newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAtTail(Node *&tail, int data)

{
    Node *newNode = new Node(data);
    if(tail == NULL){
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at last
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
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
int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void deleteNode(Node* &head, Node* &tail, int position){
    if(position == 1){
        Node* temp = head;
        Node* curr = head->next;
        head = head->next;
        curr->prev = NULL;
        delete temp;
    }
    else{
        Node* current = head;
        Node* previous = NULL;
        int cnt = 1;
        while(cnt<position){
            previous = current;
            current = current->next;
            cnt++;
        }
        current->prev = NULL;
        previous->next = current->next;
        current->next = NULL;
        delete current;
        

    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    cout << getLength(head) << endl;
    insertAtHead(head, 9);
    print(head);
    insertAtTail(tail, 12);
    print(head);
    insertAtPosition(head, tail, 11, 3);
    print(head);
    insertAtPosition(head, tail, 8, 1);
    print(head);
    insertAtPosition(head, tail, 13, 6);
    print(head);
    deleteNode(head,tail,1);
    print(head);
    deleteNode(head,tail,5);
    print(head);

    return 0;
}