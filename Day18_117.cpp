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
    int maxHeight(TreeNode* root){
        if(!root){
            return 0;
        }

        return max(maxHeight(root -> left), maxHeight(root -> right)) + 1;
    }

    int maxDepth(TreeNode* root) {
        // Q. Maximum Depth of Binary Tree
        return maxHeight(root);
    }
};