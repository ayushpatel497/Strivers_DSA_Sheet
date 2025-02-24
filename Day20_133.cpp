/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBST(vector<int>& nums, int start, int end){
        if(end  <= start) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root -> left = buildBST(nums, start, mid);
        root -> right = buildBST(nums, mid + 1, end);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Q. Convert Sorted Array to Binary Search Tree
        buildBST(nums, 0, nums.size());
    }
};