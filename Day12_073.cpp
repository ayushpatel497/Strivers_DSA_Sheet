#include <bits/stdc++.h> 
class Node{
    public:
    int data;
    int row;
    int col;
    
    Node(int data, int row, int col){
        this -> data = data;
        this -> row = row;
        this -> col = col;
    }
};
class compare{
    public:
    bool operator()(Node*a, Node*b){
        return a -> data > b -> data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Q. Merge K Sorted Arrays
    // Write your code here. 
    priority_queue<Node*, vector<Node*>, compare>pq;
 
    for(int i = 0; i < k; ++i){
          
        if(!arr[i].empty()){
            pq.push(new Node(arr[i][0], i, 0));
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        Node* fNode = pq.top();
        int data = fNode -> data;
        int row = fNode -> row;
        int col = fNode -> col;
        pq.pop();
        ans.push_back(data);
        if(col + 1 < arr[row].size()){
              pq.push(new Node(arr[row][col+1], row, col + 1));
        }
  
    }
    return ans;
}