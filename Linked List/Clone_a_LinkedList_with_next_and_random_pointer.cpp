#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *arb;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
    }
};
void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
Node *copyList(Node *head)
{
    // Approach 1
    // Clone a linked list with next pointers only and then run the two nested loops for random pointers
    // T.C. = O(N^2)
    // S.C. = O(1)

    // Approach 2
    // Clone the linked list with next pointers only and then make a mapping

    // clone->random = mapping[original->random]
    // T.C. = O(N)
    // S.C = O(N)

    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }
    unordered_map<Node *, Node *> mapping;
    temp = head;
    Node *temp2 = cloneHead;
    while (temp != NULL || temp2 != NULL)
    {
        mapping[temp] = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp = head;
    temp2 = cloneHead;
    while (temp != NULL)
    {
        temp2->arb = mapping[temp->arb];
        temp2 = temp2->next;
        temp = temp->next;
    }
    return cloneHead;

    // Approach 3

    // Do this in S.C. = O(1)
    // Basically we do not have to use map i.e. we have to change the links

    // Step1 Create a clone list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // Step2 Clone nodes add in b/w original list
    Node *originalNode = head;
    Node *cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // Step3  temp->next->random = temp->random->next
    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            if (temp->arb != NULL)
            {
                temp->next->arb = temp->arb->next;
            }
            else
            {
                temp->next->arb = temp->arb;
            }
        }
        temp = temp->next->next;
    }
    // Step4 Revert changes done in step2

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode != NULL)
        {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }
    // Step5 Return answer
    return cloneHead;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    return 0;
}