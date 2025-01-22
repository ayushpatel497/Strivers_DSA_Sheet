class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Q. Kth Largest Element in an Array
        priority_queue<int> pq(nums.begin(), nums.end());
        while(--k)
            pq.pop();
        return pq.top();
    }
};