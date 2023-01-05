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
Node *FloydCycleDectection(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    else
    {
        Node *slow = head;
        Node *fast = head;
        while (slow != NULL && fast != NULL)
        {

            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            if (slow == fast)
            {
                return slow;
            }
        }
        return NULL;
    }
}
Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }
    else{
        Node* intersection = FloydCycleDectection(head);
        if(intersection==NULL){
            return NULL;
        }
        Node* slow = head;
        while(slow!=intersection){
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
}
void removeLoop(Node* head){
    if(head==NULL){
        return;
    }
    Node* beginning = getStartingNode(head);
    Node* temp = beginning->next;
    while(temp->next !=beginning){
        temp = temp -> next;
    }
    temp->next = NULL;
}
void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *node3 = new Node(3);
    node2->next = node3;
    Node *node4 = new Node(4);
    node3->next = node4;
    Node *node5 = new Node(5);
    node4->next = node5;
    Node *node6 = new Node(6);
    node5->next = node6;
    node6->next = node2;
    if (FloydCycleDectection(head))
    {
        cout << "YES " << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    cout<<"Starting Node of Loop is "<< getStartingNode(head)->data<<endl;
    removeLoop(head);
    print(head);
    return 0;
}