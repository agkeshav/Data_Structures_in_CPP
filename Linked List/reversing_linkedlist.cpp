#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node* reverse(Node* &head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        
        
    }
    return prev;
}
Node* reverseRecursive(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* chotahead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotahead;
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(3);
    Node* head = node1;
    Node* node2 = new Node(5);
    node1->next = node2;
    Node* node3 = new Node(7);
    node2->next = node3;
    Node* node4 = new Node(9);
    node3->next = node4;
    print(head);
    head = reverse(head);
    print(head);

return 0;
}