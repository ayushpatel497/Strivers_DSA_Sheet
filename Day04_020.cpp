class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Q. 4Sum
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
        vector<vector<int>> ans;
        if (start == nums.size()) {
            return ans;
        }
        long long average_value = target / k;
        if (nums[start] > average_value || average_value > nums.back()) {
            return ans;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (auto temp : kSum(nums, target - nums[i], i + 1, k - 1)) {
                    ans.push_back({nums[i]});
                    ans.back().insert(ans.back().end(), temp.begin(), temp.end());
                }
            }
        }

        return ans;
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> ans;
        int i = start, j = int(nums.size()) - 1;

        while (i < j) {
            int curr_sum = nums[i] + nums[j];
            if (curr_sum < target || (i > start && nums[i] == nums[i - 1])) {
                ++i;
            } else if (curr_sum > target || (j < nums.size() - 1 && nums[j] == nums[j + 1])) {
                --j;
            } else {
                ans.push_back({nums[i++], nums[j--]});
            }
        }

        return ans;
    }
};