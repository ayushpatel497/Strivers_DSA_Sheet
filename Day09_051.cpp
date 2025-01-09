class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Q. Combination Sum
        vector<vector<int>> ans;
        vector<int> curr;
        solve(candidates, target, 0, curr, ans);
        return ans;
    }

    void solve(vector<int>& candidates, int target, int index, vector<int>& curr, vector<vector<int>>& ans){
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(curr);
            }
            return;
        }

        if (candidates[index] <= target) {
            curr.push_back(candidates[index]);
            solve(candidates, target - candidates[index], index, curr, ans);
            curr.pop_back();
        }

        solve(candidates, target, index + 1, curr, ans);
    }
};