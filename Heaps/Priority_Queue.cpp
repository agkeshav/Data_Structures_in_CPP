// STL for heap
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"using priortiy queue"<<endl;// This is a max heap
    // Max heap
    priority_queue<int> pq;
    pq.push(1);
    pq.push(8);
    pq.push(5);
    pq.push(4);
    pq.push(11);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    // Min heap
    priority_queue<int, vector<int> , greater<int>> minHeap;

    minHeap.push(1);
    minHeap.push(8);
    minHeap.push(5);
    minHeap.push(4);
    minHeap.push(11);
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
    return 0;
}