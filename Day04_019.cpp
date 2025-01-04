class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Q. Two Sum
        unordered_map<int, int> um;
        int i = 0;
        while(i < nums.size()){
            if(um.count(target - nums[i])){
                return {um[target - nums[i]], i};
            }
            else{
                um[nums[i]] = i;
            }
            i++;
        }
        return {0,0};
    }
};