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
bool isCircular(Node* head){
    Node* temp = head->next;
    while(temp!=NULL && temp!= head){
        temp = temp->next;
    }
    if(temp==head){
        return true;
    }
    else{
        return false;
    }
}
void print(Node* &head)
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
    Node *node1 = new Node(1);
    Node *head = node1;
    Node* node2 = new Node(2);
    node1->next = node2;
    Node* node3 = new Node(3);
    node2->next = node3;
    node3->next = node1;
    cout<<isCircular(head)<<endl;
   
    return 0;
}