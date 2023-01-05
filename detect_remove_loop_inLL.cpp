#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
    }
};
bool isCycle(Node *head)
{
    unordered_map<Node *, bool> visited;
    Node *temp = head;
    while(temp != NULL){
        //cycle is present
        if(visited[temp]==true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* node2 = new Node(2);
    node1->next = node2;
    Node* node3 = new Node(3);
    node2->next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4->next = node5;
    Node* node6 = new Node(6);
    node5->next = node6;
    node6->next = node2;
    cout<<"Is Cycle present "<<isCycle(head)<<endl;
    return 0;
}