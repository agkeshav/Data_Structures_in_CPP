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
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void insertAtTail(Node* &ansHead, Node* &ansTail, int val){
    Node* newNode = new Node(val);
    if(ansHead == NULL){
        ansHead = newNode;
        ansTail = newNode;
    }
    else{
        ansTail->next = newNode;
        ansTail = newNode;
    }
}
Node *add(Node *first, Node *second)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while (first != NULL && second != NULL)
    {
        int sum = carry + first->data + second->data;
        int digit = sum % 10;
        carry = sum / 10;
        insertAtTail(ansHead,ansTail,digit);
        first = first->next;
        second = second->next;
    }
    while(first!=NULL){
        int sum = carry +first->data;
        int digit = sum % 10;
        carry = sum / 10;
        insertAtTail(ansHead,ansTail,digit);
        first = first->next;
    }
    while(second != NULL){
        int sum = carry + second -> data;
         int digit = sum % 10;
        carry = sum / 10;
        insertAtTail(ansHead,ansTail,digit);
        second = second->next;
    }
    while(carry != 0){
        int sum = carry;;
         int digit = sum % 10;
        carry = sum / 10;
        insertAtTail(ansHead,ansTail,digit);
    }
    return ansHead;
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
    Node *head1 = new Node(4);
    head1->next = new Node(5);
    Node *head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = new Node(5);

    // Step 1 reverse both LL
    head1 = reverse(head1);
    head2 = reverse(head2);

    // Step 2 add both LL

    Node *ansHead = add(head1, head2);

    // Step3 reverse the answer linked list
    ansHead = reverse(ansHead);
    print(ansHead);

    return 0;
}