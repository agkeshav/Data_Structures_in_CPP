#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
Node *mergeKLists(Node *arr[], int K)
{
    // Your code here
    Node *head = NULL;
    Node *tail = NULL;
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (int i = 0; i < K; i++)
    {
        if (arr[i] != NULL)
        {
            pq.push(arr[i]);
        }
    }

    while (pq.size() > 0)
    {
        Node *top = pq.top();
        if (head == NULL)
        {
            head = top;
            tail = top;
            pq.pop();
            if (top->next != NULL)
            {
                pq.push(top->next);
            }
        }
        else
        {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if (tail->next != NULL)
            {
                pq.push(tail->next);
            }
        }
    }
    return head;
}
int main()
{

    return 0;
}
