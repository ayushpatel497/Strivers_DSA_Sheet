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
    bool isPossible(TreeNode* root, long long leftVal, long long rightVal){
        if(!root){
            return true;
        }
        if(root -> val < rightVal && root -> val > leftVal){
            return isPossible(root -> left, leftVal, root -> val) && isPossible(root -> right, root -> val, rightVal);
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        // Q. Validate Binary Search Tree
        return isPossible(root, -10000000000 , 10000000000);
    }
};