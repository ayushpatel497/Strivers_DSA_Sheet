class Solution {
    bool recursion(int index, int numsSize, vector<int>& nums, int target){
        if(index >= numsSize || target < 0){
            return false;
        }
        if(target == 0){
            return true;
        }
        bool include = recursion(index + 1, numsSize, nums, target - nums[index]);
        bool exclude = recursion(index + 1, numsSize, nums, target);

        return include || exclude;
    }

    bool memoization(int index, int numsSize, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(index >= numsSize || target < 0){
            return false;
        }
        if(target == 0){
            return true;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool include = memoization(index + 1, numsSize, nums, target - nums[index], dp);
        bool exclude = memoization(index + 1, numsSize, nums, target, dp);

        return dp[index][target] = include || exclude;
    }

    bool tabulation(int numsSize, vector<int>& nums, int target){
        vector<vector<bool>> dp(numsSize + 1, vector<bool>(target + 1, false));
        for(int index = 0; index <= numsSize; ++index){
            dp[index][0] = true;
        }
        for(int index = numsSize - 1; index >= 0; --index){
            for(int targt = 0; targt <= target; ++targt){
                bool include;
                if(targt - nums[index] >= 0){
                    include = dp[index + 1][targt - nums[index]];
                }
                bool exclude = dp[index + 1][targt];
                dp[index][targt] = include || exclude;
            }
        }
        return dp[0][target];
    }

    bool spaceOptimized(int numsSize, vector<int>& nums, int target){
        vector<bool> curr(target + 1, false);
        vector<bool> next(target + 1, false);
        curr[0] = true;
        next[0] = true;
        for(int index = numsSize - 1; index >= 0; --index){
            for(int targt = 0; targt <= target; ++targt){
                bool include = false;
                if(targt - nums[index] >= 0){
                    include = next[targt - nums[index]];
                }
                bool exclude = next[targt];
                curr[targt] = include || exclude;
            }
            next = curr;
        }
        return next[target];
    }

public:
    bool canPartition(vector<int>& nums) {
        // Q. Partition Equal Subset Sum
        int total = 0;
        int numsSize = nums.size();
        for(int index = 0; index < numsSize; ++index){
            total += nums[index];
        }
        if(total & 1){
            return false;
        }
        int target = total / 2;
        return recursion(0, numsSize, nums, target);
        vector<vector<bool>> dp(numsSize, vector<bool>(target + 1, -1));
        return memoization(0, numsSize, nums, target, dp);
        return tabulation(numsSize, nums, target);
        return spaceOptimized(numsSize, nums, target);
    }
};