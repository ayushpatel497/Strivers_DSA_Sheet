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
    TreeNode* buildBST(vector<int>& preorder, int start, int end){
        if(end < start){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[start]);
        int position = start;
        for(int index = start + 1; index <= end; ++index){
            if(preorder[index] <  root -> val){
                position = index;
            }
            else{
                break;
            }
        }

        root -> left = buildBST(preorder, start + 1, position);
        root -> right = buildBST(preorder, position + 1, end);

        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Q. Construct Binary Search Tree from Preorder Traversal
        return buildBST(preorder, 0, preorder.size() - 1);
    }
};