#include <iostream>
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
class Stack
{
    Node *head;
    Node *tail;

public:
    Stack()
    {
        head = NULL;
        tail = NULL;
    }

public:
    void push(int element)
    {
        Node *newNode = new Node(element);
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
    void pop()
    {
        if (head == NULL || tail == NULL)
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            if(head == tail){
                head = NULL;
                tail =  NULL;
                
            }
            Node *temp = head;
            Node *prev = NULL;
            while (temp != tail)
            {
                prev = temp;
                temp = temp->next;
            }
            Node* deleteNode = tail;
            prev->next = NULL;
            tail = prev;
            delete  deleteNode;
        }
    }
    int peek()
    {
        int a = tail->data;
        return a;
    }
    bool isEmpty()
    {
        return (head);
    }
};
int main()
{
    Stack st;
    st.push(22);
    cout << st.peek() << endl;
    st.push(43);
    cout << st.peek() << endl;
    st.push(44);
    cout << st.peek() << endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    cout << st.isEmpty() << endl;

    return 0;
}