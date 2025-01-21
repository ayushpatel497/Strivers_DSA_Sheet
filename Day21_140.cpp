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
    void recursiveCall(TreeNode* root, int k, int& kthSmallestVal, int& counter){
        if(!root || counter >= k){
            return;
        }
        recursiveCall(root -> left, k, kthSmallestVal, counter);
        counter += 1;
        if(counter == k){
            kthSmallestVal = root -> val;
            return;
        }
        recursiveCall(root -> right, k, kthSmallestVal, counter);
    }
    int kthSmallest(TreeNode* root, int k) {
        // Q. Kth Smallest Element in a BST
        int kthSmallestVal = INT_MIN;
        int counter = 0;
        recursiveCall(root, k, kthSmallestVal, counter);
        return kthSmallestVal;
    }
};