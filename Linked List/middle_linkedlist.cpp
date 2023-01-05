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
struct Node *middleNode (Node* &head){
    Node* fast = head->next;
    Node* slow = head;
    if(head==NULL || head->next ==NULL){
        return head;
    }
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
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
    Node* node5 = new Node(11);
    node4->next = node5;
    Node* middle = middleNode(head);
    cout<<middle->data<<endl;
   

return 0;
}