class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Q. Longest Consecutive Sequence
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxAns = 0;
        int ans = 1;
        int lastSmallest = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - 1 == lastSmallest) {
                ans += 1;
                lastSmallest = nums[i];
            }
            else if (nums[i] != lastSmallest) {
                ans = 1;
                lastSmallest = nums[i];
            }
            maxAns = max(maxAns, ans);
        }

        return maxAns;
    }
};