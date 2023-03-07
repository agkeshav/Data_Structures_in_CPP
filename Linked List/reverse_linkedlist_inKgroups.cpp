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
int getLen(node *head)
{
    node *temp = head;
    int ans = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        ans++;
    }
    return ans;
}
Node *reverseInKGroups(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;
        int cnt = 0;
        while (cnt != k)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }
        if (getLen(forward) < k)
        {
            head->next = forward;
        }
        else
        {
            head->next = reverseKGroup(forward, k);
        }
        return prev;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
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
    print(head);
    Node *reverseLLhead = reverseInKGroups(head, 2);
    print(reverseLLhead);

    return 0;
}