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
    bool findTarget(TreeNode* root, int k) {
        // Q. Two Sum IV - Input is a BST
        if(!root){
            return false;
        }
        stack<TreeNode *> s1, s2;
        TreeNode* temp1 = root;
        TreeNode* temp2 = root;

        while(true){
            while(temp1){
                s1.push(temp1);
                temp1 = temp1 -> left;
            }
            while(temp2){
                s2.push(temp2);
                temp2 = temp2 -> right;
            }

            if(s1.empty() || s2.empty()){
                break;
            }

            temp1 = s1.top();
            temp2 = s2.top();

            if((temp1 -> val + temp2 -> val) == k){
                if(temp1 == temp2){
                    return false;
                }
                return true;
            }
            else if((temp1 -> val + temp2 -> val) < k){
                s1.pop();
                temp1 = temp1 -> right;
                temp2 = NULL;
            }
            else{
                s2.pop();
                temp2 = temp2 -> left;
                temp1 = NULL;
            }
        }

        return false;
    }
};