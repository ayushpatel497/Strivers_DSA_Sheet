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
    void recursiveTraversal(TreeNode *root, vector<int>& ans){
        if(!root){
            return;
        }
        recursiveTraversal(root -> left, ans);
        ans.emplace_back(root -> val);
        recursiveTraversal(root -> right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // Q. Binary Tree Inorder Traversal
        vector<int> ans;
        recursiveTraversal(root, ans);
        return ans;
    }
};