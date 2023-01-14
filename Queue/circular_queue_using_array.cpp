#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
    int front;
    int rear;
    int* arr;
    int size;
    CircularQueue(int n){
        // Write your code here.
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size];
        
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            return false;
        }
        else if(front == -1){
            front = 0;
            rear = 0;
            arr[rear] = value;
            return true;
        }
        else if(rear == size -1 && front!=0){
            rear = 0;
            arr[rear] = value;
            return true;
        }
        else{
            rear++;
            arr[rear] = value;
            return true;
        }
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front == -1){
            return -1;
        }
        else if(front == rear){
            int ans = arr[front];
            front=rear=-1;
            return ans;
        }
        else if(front == size-1){
             int ans = arr[front];
            front = 0;
            return ans;
        }
        else{
             int ans = arr[front];
            front++;
            return ans;
        }
    }
};