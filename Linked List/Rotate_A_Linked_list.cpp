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
Node *rotate(Node *head, int k)
{
    // Your code here
    int cnt = 1;
    Node* curr = head;
    while(cnt != k){
        curr = curr -> next;
        cnt++;
    }
    
    Node* head1 = curr -> next;
    if(head1 == NULL){ // This means that k is equal to the length of the linked list. In this we dont need to rotate as the output will be same as input.
        return head;
    }
    curr->next = NULL;
    Node* temp = head1;
    while(temp->next!=NULL){
        temp = temp -> next;

    }
    temp->next = head;
    return head1;
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
    head = rotate(head,2);
    print(head);

    return 0;
}