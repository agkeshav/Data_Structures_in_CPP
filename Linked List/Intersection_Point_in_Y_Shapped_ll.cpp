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
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    if(head1==NULL){
        return head2->data;
    }
    if(head2==NULL){
        return head1->data;
    }
    int l1=0;
    Node* temp = head1;
    while(temp!=NULL){
        l1++;
        temp = temp -> next;
    }
    int l2 = 0;
    temp = head2;
     while(temp!=NULL){
        l2++;
        temp = temp -> next;
    }
    int cnt;
    if(l1>l2){
        cnt = l1 - l2;
        Node* curr = head1;
        while(cnt!=0){
            curr = curr -> next;
            cnt--;
        }
        Node* curr1 = head2;
        while(curr!=curr1){
            curr = curr -> next;
            curr1 = curr1 -> next;
        }
        return curr->data;
    }
    else{
        cnt = l2 - l1;
         Node* curr = head2;
        while(cnt!=0){
            curr = curr -> next;
            cnt--;
        }
        Node* curr1 = head1;
        while(curr!=curr1){
            curr = curr -> next;
            curr1 = curr1 -> next;
        }
        return curr->data;
    }
    return -1;

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
    Node *head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = new Node(15);
    head1->next->next->next->next = new Node(30);
    print(head1);
    Node *head2 = new Node(10);
    head2->next = head1->next->next->next;
    head2->next->next = head1->next->next->next->next;
    print(head2);
    cout<<intersectPoint(head1,head2)<<endl;

    return 0;
}