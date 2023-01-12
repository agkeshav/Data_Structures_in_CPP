#include <bits/stdc++.h>
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
Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head -> next;
    while(fast!=NULL && fast ->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* ansHead = new Node(-1);
    Node* temp = ansHead;
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right!=NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ansHead = ansHead->next;
    return ansHead;

}
Node *mergeSort(Node *head){
    // your code here
    if(head == NULL || head->next==NULL){
        return head;
    }
    Node* left = head;
    Node* mid = findMid(head);
    Node* right = mid -> next;
    mid->next = NULL;

    // recursive calls
    left = mergeSort(left);
    right = mergeSort(right);

    Node* result = merge(left,right);
    return result;
    
    
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
    Node *head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);
    print(head);
    Node* ans = mergeSort(head);
    print(ans);
   

    return 0;
}