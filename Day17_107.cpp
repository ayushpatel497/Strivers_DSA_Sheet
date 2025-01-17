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
    vector<int> inorderTraversal(TreeNode* root) {
        // Q. Binary Tree Morris Inorder Traversal
        vector<int> ans;
        TreeNode *curr = root;
        TreeNode *pre;

        while(curr){
            if(!curr -> left){
                ans.emplace_back(curr -> val);
                curr = curr -> right;
            }
            else{
                pre = curr -> left;
                while(pre -> right && pre -> right != curr){
                    pre = pre -> right;
                }
                if(!pre -> right){
                    pre -> right = curr;
                    curr = curr -> left;
                }
                else{
                    pre -> right = NULL;
                    ans.emplace_back(curr -> val);
                    curr = curr -> right;
                }
            }
        }

        return ans;
    }
};