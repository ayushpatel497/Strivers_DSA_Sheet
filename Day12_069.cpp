#include <bits/stdc++.h>
using namespace std;
 
void insert(vector<int>& heap, int element) {
    heap.push_back(element);
    int childInd = heap.size() - 1;
    while (childInd > 1) {
        int parentInd = childInd / 2;
        if (heap[childInd] < heap[parentInd]) {
            swap(heap[childInd], heap[parentInd]);
        } 
        else {
            break;
        }
        childInd = parentInd;
    }
}
 
int remove(vector<int>& heap) {
    if (heap.size() == 1) 
        return -1;

    int element = heap[1];
    swap(heap[1], heap[heap.size() - 1]);
    heap.pop_back();
    int parentInd = 1;
    int n = heap.size();
    int minInd;
 
    while (parentInd < n) {
        int lchildInd = 2 * parentInd;
        int rchildInd = 2 * parentInd + 1;
        minInd = parentInd;
 
        if (lchildInd < n && heap[lchildInd] < heap[minInd]) {
            minInd = lchildInd;
        }
        if (rchildInd < n && heap[rchildInd] < heap[minInd]) {
            minInd = rchildInd;
        }
        if (minInd == parentInd) {
            break;
        }
        swap(heap[parentInd], heap[minInd]);
        parentInd = minInd;
    }
    return element;
}
 
vector<int> minHeap(vector<vector<int>>& queries) {
    // Q. Min Heap
    vector<int> ans;
    vector<int> heap;
    heap.push_back(-1);
    for (int i = 0; i < queries.size(); ++i) {
        if (queries[i][0] == 0) {
            insert(heap, queries[i][1]);
        } 
        else {
            ans.push_back(remove(heap));
        }
    }
    return ans;
}