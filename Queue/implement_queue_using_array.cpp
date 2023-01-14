#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        front = 0;
        rear = 0;
        arr = new int[size];
    }
public:
    bool isEmpty(){
        if(front == rear || rear == size){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int data){
        if(rear == size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }
public:
    int front1(){
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    int dequeue(){
        if(front==rear){
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }

    }
    
};
int main()
{
    Queue q1(10);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    cout<<q1.front1()<<endl;
    return 0;
}