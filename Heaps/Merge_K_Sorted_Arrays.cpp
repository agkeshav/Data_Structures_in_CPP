#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    int row;
    int col;
public:
    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class Compare{
public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // code here
    vector<int> ans;
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(int i=0;i<arr.size();i++){
        pq.push(new Node(arr[i][0],i,0));
    }
    

    while(pq.size()>0){
        int r = pq.top()->row;
        int c = pq.top()->col;
        ans.push_back(pq.top()->data);
        pq.pop();
        if(c+1 < arr[r].size()){
            pq.push(new Node(arr[r][c+1],r,c+1));
        }

    }
    return ans;
}
int main()
{

    return 0;
}