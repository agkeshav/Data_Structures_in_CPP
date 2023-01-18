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
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *insertAtTail(Node *&ansHead, Node *&ansTail, int val)
{
    Node *newNode = new Node(val);
    if (ansHead == NULL)
    {
        ansHead = newNode;
        ansTail = newNode;
    }
    else
    {
        ansTail->next = newNode;
        ansTail = newNode;
    }
}
Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one

    Node *temp = reverse(head);
    Node *ans = temp;
    Node *ansTail = NULL;
    Node *ansHead = NULL;
    int carry = 0;
    int k = 1;
    int sum;
    while (temp != NULL)
    {
        if (k == 1)
        {
            sum = temp->data + 1 + carry;
        }
        else
        {
            sum = temp->data + carry;
        }
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        temp = temp->next;
        k--;
    }
    while (carry != 0)
    {
        sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        insertAtTail(ansHead, ansTail, digit);
    }
    return reverse(ansHead);
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
    Node *head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(6);
    print(head);
    Node* ans = addOne(head);
    print(ans);
   

   

    return 0;
}