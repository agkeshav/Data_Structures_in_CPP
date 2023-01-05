#include <iostream>
using namespace std;
class Stack
{
    int *arr;
    int top;
    int size;
    public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

public:
    void push(int element)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = element;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            top--;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            int a = arr[top];
            return a;
        }
        else
        {
            return -1;
        }
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};
int main()
{
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);
    cout<<st.peek()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl;

    return 0;
}