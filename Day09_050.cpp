class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Q. Subsets II
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        solve(nums, 0, subset, ans);
        return ans;
    }

    void solve(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i = index; i < nums.size(); ++i){
            if(i > index && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            solve(nums, i + 1, curr, ans);
            curr.pop_back();
        }
    }
};