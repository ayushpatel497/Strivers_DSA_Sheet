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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Q. Search in a Binary Search Tree
        if(!root){
            return NULL;
        }
        
        int rootVal = root -> val;
        if(rootVal == val){
            return root;
        }
        else if(rootVal < val){
            return searchBST(root -> right, val);
        }
        else{
            return searchBST(root -> left, val);
        }
    }
};