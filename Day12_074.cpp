class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Q. Top K Frequent Elements
        unordered_map<int, int> um;
        for(int num : nums){
            um[num]++;
        }
        
        vector<int> ans;
        priority_queue<pair<int, int>> pq; 
        for(auto it = um.begin(); it != um.end(); ++it){
            pq.push({it -> second, it -> first});
            if(pq.size() > um.size() - k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};