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
Node* solve(Node* first, Node* second){
    Node* curr1 = first;
    Node* next1 = first->next;
    Node* curr2 = second;
    //if only one element present in first list
    if(first->next==NULL){
        first->next = second;
        return first;
    }
    while(next1 != NULL && curr2 != NULL){
        if(curr2->data>=curr1->data && curr2->data <= next1->data){
            curr1->next = curr2;
            Node* next2  =curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            // curr1 and next1 ko aage bhadana hai
            curr1 = next1;
            next1 = next1->next;
            if(next1==NULL){
                curr1->next = curr2;
            }
        }
    }
    return first;
}
Node* merge2sortedLL(Node* head1,Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    if(head1->data<=head2->data){
        return solve(head1,head2);
    }
    else{
        return solve(head2,head1);
    }
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
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(5);
    print(head1);
    print(head2);
    Node* head = merge2sortedLL(head1,head2);
    print(head);
    return 0;
}