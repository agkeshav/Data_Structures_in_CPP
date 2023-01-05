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
Node* getMiddle(Node* &head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next !=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    return prev;
}
bool check(Node* &head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    // Step1 find middle of the linked list
    Node* middle = getMiddle(head);
    Node* temp = middle->next;
    // Step 2 reverse the linked list after middle
    middle->next = reverse(temp);
    Node* head1 = head;
    Node* head2 = middle->next;
    while(head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;



}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);
    print(head);
    cout<<check(head)<<endl;
    print(head);
    
   
    return 0;
}