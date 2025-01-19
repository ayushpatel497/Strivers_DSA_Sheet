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
    int getMaximumSum(TreeNode *root, int& maximumSum){
        if(!root){
            return 0;
        }
        int leftSum = max(0, getMaximumSum(root -> left, maximumSum));
        int rightSum = max(0, getMaximumSum(root -> right, maximumSum));
        maximumSum = max(maximumSum, leftSum + rightSum + root -> val);

        return max(leftSum, rightSum) + root -> val;
    }

    int maxPathSum(TreeNode* root) {
        // Q. Binary Tree Maximum Path Sum
        int maximumSum = INT_MIN;
        getMaximumSum(root, maximumSum);
        return maximumSum;
    }
};